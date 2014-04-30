// http://oj.leetcode.com/problems/restore-ip-addresses/

class Solution {
    void do_restore(string& str, int beg, vector<string>& ret, string tmp, int remaining) {
        int size = str.size() - beg;
        
        if (remaining == 0 && size == 0) {
            string r = tmp;
            ret.push_back(r);
            return;
        }
        if (size < remaining || size > 3 * remaining) {
            return;
        }
        
        for (int i = 1; i <= 3; i++) {
            // eliminate the unnecessary head zero
            if (i != 1 && str[beg] == '0') {
                continue;
            }
            
            string part = str.substr(beg, i);
            int num = stoi(part, nullptr);
            
            if (num <= 255 && num >= 0) {
                if (remaining > 1) {
                    part += ".";
                }
                do_restore(str, beg + i, ret, tmp + part, remaining - 1);
            }
        }
    }

public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ret;
        string tmp = "";
        do_restore(s, 0, ret, tmp, 4);
        
        return ret;
    }
};