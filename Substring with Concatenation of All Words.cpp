// https://oj.leetcode.com/problems/substring-with-concatenation-of-all-words/

class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        vector<int> ret;
        if (L.size() == 0) {
            return ret;
        }
        
        int str_size = S.size();
        int list_size = L.size();
        int word_len = L[0].size();
        int concat_len = list_size * word_len;
        if (str_size < concat_len) {
            return ret;
        }
        
        unordered_map<string, int> list_map;
        for (int i = 0; i < list_size; i++) {
            list_map[L[i]]++;
        }
        
        int move_len = str_size - concat_len;
        unordered_map<string, int> tmp;
        for (int i = 0; i <= move_len; i++) {
            int len = i + concat_len;
            bool matched = true;
            
            tmp.clear();
            for (int j = i; j < len; j += word_len) {
                string snippet = S.substr(j, word_len);
                if (list_map.count(snippet) == 0) {
                    matched = false;
                    break;
                }
                tmp[snippet]++;
                if (tmp[snippet] > list_map[snippet]) {
                    matched = false;
                    break;
                }
            }
            if (matched) {
                ret.push_back(i);
            }
        }
        
        return ret;
    }
};