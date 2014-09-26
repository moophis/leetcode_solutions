// https://oj.leetcode.com/problems/multiply-strings/

class Solution {
    string add(vector<string> &strs) {
        int carry = 0; 
        string ret = "";
        
        int idx = 0;
        while (true) {
            bool processed_all = true;
            int sum = carry;
            for (int i = 0; i < strs.size(); i++) {
                if (idx >= strs[i].size()) {
                    continue;
                }
                processed_all = false;
                sum += (strs[i][idx] - '0');
            }
            if (processed_all) {
                break;
            }
            
            int cur_digit = sum % 10;
            carry = sum / 10;
            ret = static_cast<char>(cur_digit + '0') + ret;
            
            idx++;
        }
        
        while (carry > 0) {
            int digit = carry % 10;
            ret = static_cast<char>(digit + '0') + ret;
            carry = carry / 10;
        }
        
        // removing heading 0s
        int i = 0;
        while (i < ret.size()) {
            if (ret[i] != '0') {
                break;
            }
            i++;
        }
        
        return (i == ret.size()) ? "0" : ret.substr(i);
    }

public:
    string multiply(string num1, string num2) {
        int size1 = num1.size(), size2 = num2.size();
        
        if (size1 == 0 || size2 == 0) {
            return "";
        }
         
        vector<string> lines;
        int zero_paddings = 0;
        for (int i = size1 - 1; i >= 0; i--) {
            string cur_line = "";
            int carry = 0;
            for (int j = size2 - 1; j >= 0; j--) {
                int d1 = num1[i] - '0';
                int d2 = num2[j] - '0';
                int tmp = d1 * d2 + carry;
                int digit = tmp % 10;
                carry = tmp / 10;
                cur_line += static_cast<char>(digit + '0');
            }
            if (carry != 0) {
                cur_line += static_cast<char>(carry + '0');
            }
            for (int j = 0; j < zero_paddings; j++) {
                cur_line = '0' + cur_line;
            }
            zero_paddings++;
            lines.push_back(cur_line);
        }
        
        return add(lines);
    }
};