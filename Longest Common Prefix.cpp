// http://oj.leetcode.com/problems/longest-common-prefix/

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if (strs.size() == 0) {
            return "";
        }
        if (strs.size() == 1) {
            return strs[0];
        }
        
        int strs_size = strs.size();
        int max_len = strs[0].size();
        string ref = strs[0];
        string ret = "";
        
        for (int i = 0; i < max_len; i++) {
            char c = ref[i];
            
            for (int j = 1; j < strs_size; j++) {
                if (strs[j].size() <= i || strs[j][i] != c) {
                    return ret;
                }
            }
            ret += c;
        }
        
        return ret;
    }
};