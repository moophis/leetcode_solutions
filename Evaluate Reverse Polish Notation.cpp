/**
 * Evaluate the value of an arithmetic expression in Reverse Polish Notation.
 *
 * Valid operators are +, -, *, /. Each operand may be an integer or another expression.
 *
 * Some examples:
 * ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
 * ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
 */

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        vector<string> stk;
        
        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i] == "") {  // error case
                return INT_MAX;
            }
            
            string s1, s2;
            int op1, op2;
                
            switch (tokens[i][0]) {
            case '+': 
                s1 = stk.back();
                stk.pop_back();
                s2 = stk.back();
                stk.pop_back();
                op1 = atoi(s1.c_str());
                op2 = atoi(s2.c_str());
                stk.push_back(to_string(op2 + op1));
                break;
            case '-':
                if (tokens[i].size() > 1) { // negative number
                    stk.push_back(tokens[i]);
                } else {
                    s1 = stk.back();
                    stk.pop_back();
                    s2 = stk.back();
                    stk.pop_back();
                    op1 = atoi(s1.c_str());
                    op2 = atoi(s2.c_str());
                    stk.push_back(to_string(op2 - op1));
                }
                break;
            case '*':
                s1 = stk.back();
                stk.pop_back();
                s2 = stk.back();
                stk.pop_back();
                op1 = atoi(s1.c_str());
                op2 = atoi(s2.c_str());
                stk.push_back(to_string(op2 * op1));
                break;
            case '/':
                s1 = stk.back();
                stk.pop_back();
                s2 = stk.back();
                stk.pop_back();
                op1 = atoi(s1.c_str());
                op2 = atoi(s2.c_str());
                stk.push_back(to_string(op2 / op1));
                break;
            default: // assume experssions are grammatically correct
                if (isdigit(tokens[i][0])) {
                    stk.push_back(tokens[i]);
                } 
                break;
            }
        }
        
        return atoi(stk.back().c_str());
    }
};