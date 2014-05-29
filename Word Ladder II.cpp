// https://oj.leetcode.com/problems/word-ladder-ii/

// 1st Update:
// Very hard to pass the running time requirement.
// So far my code is still not optimal, though it 
// can pass the OJ test (roughly taking 1100ms to pass
// the test cases).
// Optimal ideas:
// 1. Build the graph first then use BFS to find path
// 2. Index words instead of using string literal
class Solution {
    class TreeNode {
    public:
        int word_index;
        TreeNode *parent;
        int level;
        TreeNode(int word_index, TreeNode *parent, int level)
        	: word_index(word_index), parent(parent), level(level) {}
    };
    
    void build_path(vector<vector<string> > &ret, vector<string> vdict, TreeNode *end_node) {
        TreeNode *cur_node = end_node;
        vector<string> vec;
        
        while (cur_node != nullptr) {
            auto it = vec.begin();
            int index = cur_node->word_index;
            if (index >= vdict.size()) {
                return;  // error case
            }
            vec.insert(it, vdict[index]);
            cur_node = cur_node->parent;
        }
        ret.push_back(vec);
    }
    
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        vector<vector<string> > ret;
        if (start.size() != end.size() || dict.size() == 0) {
            return ret;
        }
        
        const size_t wordlen = start.size();
        
        dict.emplace(start);
        dict.emplace(end);
        
        vector<unordered_set<int> > graph;
        vector<int> visited;
        vector<string> words(dict.begin(), dict.end());
        unordered_map<string, int> index_map;

        for (size_t i = 0; i < words.size(); i++) {
            index_map.emplace(words[i], i);
        }
        
        // find the indices of start and end word
        int vstart = 0, vend = 0;
        while (words[vstart] != start)
            vstart++;
        while (words[vend] != end)
            vend++;
        
        unordered_set<int> tmp;
        for (size_t k = 0; k < words.size(); k++) {
            string str = words[k];
            graph.push_back(tmp);
            visited.push_back(INT_MAX);
            for (int i = 0; i < wordlen; i++) {
                for (int j = 'a'; j <= 'z'; j++) {
                    char tmp = str[i];
                    if (j == tmp) {
                        continue;
                    }
                    str[i] = j;
                    if (dict.count(str) > 0) {
                        // store index rather than string literal
                        graph[k].emplace(index_map[str]);
                    }
                    str[i] = tmp;
                }
            }
        }
        
        int stop_level = 0;  // the level that we firstly find end word
        queue<TreeNode *> q;
        q.push(new TreeNode(vstart, nullptr, 1));
        visited[vstart] = 1;
        while (!q.empty()) {
            TreeNode *now = q.front();
            int word_index = now->word_index;
            q.pop();
            
            if (word_index == vend) {
            	// only taking into account the end words appearing in the same level
                if (stop_level == 0 || now->level == stop_level) {
                    build_path(ret, words, now);
                    stop_level = now->level;
                } else {
                    break;
                }
            } else { // intermediate levels
                if (graph[word_index].size() != 0) {
                    vector<int> to_del;
                    for (auto it = graph[word_index].begin(); it != graph[word_index].end(); ++it) {
                        int nw = *it;
                        int nlevel = visited[nw];
                        if (now->level >= nlevel) {
                            to_del.push_back(nw);
                        } else {
                            visited[nw] = now->level + 1;
                            q.push(new TreeNode(nw, now, now->level+1));
                        }
                        graph[nw].erase(word_index);
                    }
                    for (auto it = to_del.begin(); it != to_del.end(); ++it) {
                        graph[word_index].erase(*it);
                    }
                }
            }
        }
        
        return ret;
    }
};


