// https://oj.leetcode.com/problems/decode-ways/

class Solution {
public:
    int numDecodings(string s) {
        int ssize = s.size();
        if (ssize == 0) {
            return 0;
        } 
        
        vector<int> num(ssize + 1, 0);
        num[0] = 1;     // always has one way from start
        num[1] = (s[0] == '0') ? 0 : 1;
        for (int i = 2; i <= ssize; i++) {
            if (s[i-1] != '0') {
                num[i] += num[i-1];
            }
            if (s[i-2] == '1' || (s[i-2] == '2' && s[i-1] >= '0' && s[i-1] <= '6')) {
                num[i] += num[i-2];
            }
        }
        
        return num[ssize];
    }
};