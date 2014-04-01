// http://oj.leetcode.com/problems/clone-graph/


/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
    unordered_map<int, UndirectedGraphNode *> visited;
    
    UndirectedGraphNode *find_neighbor(vector<UndirectedGraphNode *> &neighbors, const int label) {
        for (int i = 0; i < neighbors.size(); i++) {
            if (label == neighbors[i]->label) {
                return neighbors[i];
            }
        }
        
        return nullptr;
    }
    
    // using DFS solution
    void dfs(UndirectedGraphNode *old_node, UndirectedGraphNode *new_node) {
        if (old_node == nullptr || new_node == nullptr) 
            return;
            
        unordered_set<int> visited_neighbors;
        
        visited.emplace(old_node->label, new_node);
        
        for (int i = 0; i < old_node->neighbors.size(); i++) {
            UndirectedGraphNode *cur = old_node->neighbors[i];
            
            // handle duplicate neighbors
            if (visited_neighbors.count(cur->label) == 0) {
                visited_neighbors.emplace(cur->label);
            } else {
                UndirectedGraphNode *dup = find_neighbor(new_node->neighbors, cur->label);
                if (dup != nullptr) {
                    new_node->neighbors.push_back(dup);
                }
                continue;
            }
            
            // handle loop
            if (visited.count(cur->label) == 0) {
                UndirectedGraphNode *new_cur = new UndirectedGraphNode(cur->label);
                new_node->neighbors.push_back(new_cur);
                visited.emplace(cur->label, new_cur);
                dfs(cur, new_cur);
            } else {
                UndirectedGraphNode *dup = visited[cur->label];
                if (dup != nullptr) {
                    new_node->neighbors.push_back(dup);
                }
            }
        }
    }
    
    // using BFS solution
    void bfs(UndirectedGraphNode *old_node, UndirectedGraphNode *new_node) {
            if (old_node == nullptr || new_node == nullptr) 
                return;
            
            list<UndirectedGraphNode *> old_q, new_q;
            old_q.push_back(old_node);
            new_q.push_back(new_node);
            while (!old_q.empty()) {
                unordered_set<int> visited_neighbors;
            
                UndirectedGraphNode *old_cur = old_q.front();
                UndirectedGraphNode *new_cur = new_q.front();
                old_q.pop_front();
                new_q.pop_front();
            
                visited.emplace(old_cur->label, new_cur);
            
                for (int i = 0; i < old_cur->neighbors.size(); i++) {
                    UndirectedGraphNode *old_ncur = old_cur->neighbors[i];
                
                    if (visited_neighbors.count(old_ncur->label) == 0) {
                        visited_neighbors.emplace(old_ncur->label);
                    } else {
                        UndirectedGraphNode *dup = find_neighbor(new_cur->neighbors, old_ncur->label);
                        if (dup != nullptr) {
                            new_cur->neighbors.push_back(dup);
                        }
                        continue;
                    }
                
                    if (visited.count(old_ncur->label) == 0) {
                        UndirectedGraphNode *new_ncur = new UndirectedGraphNode(old_ncur->label);
                        visited.emplace(old_ncur->label, new_ncur);
                        new_cur->neighbors.push_back(new_ncur);
                    
                        old_q.push_back(old_ncur);
                        new_q.push_back(new_ncur);
                    } else {
                        UndirectedGraphNode *dup = visited[old_ncur->label];
                        if (dup != nullptr) {
                            new_cur->neighbors.push_back(dup);
                        }
                    }
                }
            }
        }
    
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (node == nullptr)
            return nullptr;
            
        UndirectedGraphNode *new_node = new UndirectedGraphNode(node->label);
        dfs(node, new_node);
        
        return new_node;
    }
};