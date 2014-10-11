// https://oj.leetcode.com/problems/count-and-say/

// iteration
class Solution {
public:
    string countAndSay(int n) {
        if (n < 0) {
            return "";
        }
        if (n == 1) {
            return "1";
        }
        
        string last = "1";
        string cur = "";
        for (int i = 2; i <= n; i++) {
            string cur;
            char last_c = last[0];
            int cnt = 1; 
            for (int j = 1; j < last.size(); j++) {
                if (last[j] == last_c) {
                    cnt++;
                } else {
                    cur += to_string(cnt);
                    cur += last_c;
                    
                    cnt = 1;
                    last_c = last[j];
                }
            }
            
            cur += to_string(cnt);
            cur += last_c;
            last.assign(cur);
            cur = "";
        }
        
        return last;
    }
};

// recursion
class Solution {
public:
    string countAndSay(int n) {
        if (n <= 0) {
            return "";
        }
        if (n == 1) {
            return "1";
        }
        
        string last = countAndSay(n - 1);
        string next = "";
        
        size_t last_size = last.size();
        char cur_digit = last[0];
        int cur_count = 0;
        for (size_t i = 0; i < last_size; i++) {
            if (last[i] == cur_digit) {
                cur_count++;
            } else {
                next += to_string(cur_count);
                next += cur_digit;
                cur_digit = last[i];
                cur_count = 1;
            }
        }
        next += to_string(cur_count);
        next += cur_digit;
        
        return next;
    }
};