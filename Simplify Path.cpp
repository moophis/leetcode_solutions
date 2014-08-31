// https://oj.leetcode.com/problems/simplify-path/

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> tokens;
        int len = path.size();
        
        int i = 0;
        while (i < len) {
            while (i < len && path[i] == '/') {
                i++;
            }
            if (i == len) {
                break;
            }
            
            string token;
            while (i < len && path[i] != '/') {
                token += path[i++];
            }
            if (token.compare("..") == 0) {
                if (tokens.size() > 0) {
                    tokens.pop_back();
                }
            } else if (token.compare(".") != 0) {
                tokens.push_back(token);
            }
        }
        
        stringstream ss;
        for (auto it = tokens.begin(); it != tokens.end(); ++it) {
            ss << "/" << *it;
        }
        
        string ret = ss.str();
        return ret.size() == 0 ? "/" : ret;
    }
};