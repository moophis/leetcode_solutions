// https://oj.leetcode.com/problems/longest-substring-without-repeating-characters/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        size_t size = s.size();
        if (size == 0) {
            return 0;
        }
        
        int maxlen = 1;
        unordered_map<char, int> strmap;  // <char, last_position>
        strmap.emplace(s[0], 0);
        int begin = 0;
        for (int end = 1; end < size; end++) {
            char cur = s[end];
            if (strmap.count(cur) == 0 || strmap[cur] < begin) {
                maxlen = max(maxlen, end - begin + 1);
            } else {
                begin = strmap[cur] + 1;  // next one to the repeated character
            }
            strmap[s[end]] = end;
        } 
        
        return maxlen;
    }
};