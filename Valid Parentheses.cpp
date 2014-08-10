// https://oj.leetcode.com/problems/valid-parentheses/

class Solution {
public:
    bool isValid(string s) {
        size_t size = s.size();
        if (size == 0) {
            return true;
        }
        
        stack<char> stk;
        for (size_t i = 0; i < size; i++) {
            char c = s[i];
            
            switch (c) {
            case '(': 
            case '{':
            case '[':
                stk.push(c);
                break;
            case ')': {
                if (stk.size() == 0 || stk.top() != '(') {
                    return false;
                }
                stk.pop();
                break;
            }
            case '}': {
                if (stk.size() == 0 || stk.top() != '{') {
                    return false;
                }
                stk.pop();
                break;
            }
            case ']': {
                if (stk.size() == 0 || stk.top() != '[') {
                    return false;
                }
                stk.pop();
                break;
            }
            default:
                return false;
            }
        }
        
        return stk.size() == 0;
    }
};