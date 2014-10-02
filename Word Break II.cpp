// http://oj.leetcode.com/problems/word-break-ii/

// new solution: use a boolean array to trim unnecessary recursive calls
class Solution {
    void do_break(string &s, int begin, string &buf, 
                  vector<string> &ans, unordered_set<string> &dict, vector<bool> &possible) {
        int size = static_cast<int>(s.size());  // size_t -> unsigned int
        
        if (begin >= size) {
            int bufsize = buf.size();
            ans.push_back(buf.substr(0, bufsize - 1));
        }
        
        for (int i = 1; begin + i <= size; i++) {
            string cur_word = s.substr(begin, i);
            
            if (dict.count(cur_word) > 0 && possible[begin + i]) {
                int last_len = static_cast<int>(buf.size());
                int ans_len = ans.size();
                
                buf += cur_word;
                buf += " ";
                do_break(s, begin + i, buf, ans, dict, possible);
                if (ans.size() == ans_len) {  // if nothing changed, do not visit again
                    possible[begin + i] = false;
                }
                buf.erase(last_len);
            }
        }
    }

public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        vector<string> ans;
        string buf = "";
        
        if (s.size() == 0 || dict.size() == 0) {
            return ans;
        }
        
        vector<bool> possible(s.size(), true);
        
        do_break(s, 0, buf, ans, dict, possible);
        return ans;
    }
};

// old solution
class Solution {
    void do_break(string &s, int begin, string &buf, 
                  vector<string> &ans, unordered_set<string> &dict) {
        int size = static_cast<int>(s.size());
        
        if (begin >= size) {
            int bufsize = buf.size();
            ans.push_back(buf.substr(0, bufsize - 1));
        }
        
        for (int i = 1; begin + i <= size; i++) {
            string cur_word = s.substr(begin, i);
            
            if (dict.count(cur_word) > 0) {
                int last_len = static_cast<int>(buf.size());
                
                buf += cur_word;
                buf += " ";
                do_break(s, begin + i, buf, ans, dict);
                buf.erase(last_len);
            }
        }
    }

public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        vector<string> ans;
        string buf = "";
        
        if (s.size() == 0 || dict.size() == 0) {
            return ans;
        }
        
        // we should first check out whether the given
        // string can be broke and match the items in 
        // the dictionary accordingly.
        bool dpbuf[s.size()+1];
        memset(dpbuf, false, s.size()+1);
        dpbuf[0] = true;
        for (size_t i = 1; i <= s.size(); i++) {
            for (size_t j = 0; j < i; j++) {
                if (dpbuf[j] && dict.count(s.substr(j, i - j)) > 0) {
                    dpbuf[i] = true;
                }
            }
        }
        if (!dpbuf[s.size()]) {
            return ans;
        } 
        
        do_break(s, 0, buf, ans, dict);
        return ans;
    }
};