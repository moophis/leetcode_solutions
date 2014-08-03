// https://oj.leetcode.com/problems/longest-valid-parentheses/
// Reference:
// http://fisherlei.blogspot.com/2013/03/leetcode-longest-valid-parentheses.html

// Use a stack to match pairs
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stk;
        int maxlen = 0;
        
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            
            if (c == '(') {
                stk.push(i);
            } else {
                if (stk.size() != 0 && s[stk.top()] == '(') {
                    stk.pop();
                    // find the last character that doesn't match or all characters match
                    maxlen = max(maxlen, (stk.size() == 0) ? i + 1 : i - stk.top()); 
                } else {
                    stk.push(i);
                }
            }
        }
        
        return maxlen;
    }
};