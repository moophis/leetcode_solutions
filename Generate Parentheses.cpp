// https://oj.leetcode.com/problems/generate-parentheses/

class Solution {
    // nr_open/nr_close: # of open/close paranthesis generated
    void do_generate(vector<string> &ret, string &buf, int nr_open, int nr_close, int n) {
        if (nr_open + nr_close == 2 * n) {
            ret.push_back(buf);
            return;
        }
        
        if (nr_open < n) {
            buf.push_back('(');
            do_generate(ret, buf, nr_open + 1, nr_close, n);
            buf.pop_back();
        }
        if (nr_open > nr_close) {
            buf.push_back(')');
            do_generate(ret, buf, nr_open, nr_close + 1, n);
            buf.pop_back();
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        if (n <= 0) {
            return ret;
        }
        string buf;
        do_generate(ret, buf, 0, 0, n);
        
        return ret;
    }
};