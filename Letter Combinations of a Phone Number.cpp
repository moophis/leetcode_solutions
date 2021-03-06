// https://oj.leetcode.com/problems/letter-combinations-of-a-phone-number/

// iterative
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ret;
        if (digits.size() == 0) {
            return {""};
        }
        
        vector<string> num_map = {" ","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<int> cur_idx(digits.size(), 0);  // recording the current index of each digit
        
        while (true) {
            string buf;
            for (int i = 0; i < digits.size(); i++) {
                buf += num_map[digits[i] - '0'][cur_idx[i]];
            }
            ret.push_back(buf);
            
            int k = digits.size() - 1;
            while (k >= 0) {
                if (cur_idx[k] < num_map[digits[k] - '0'].size() - 1) {
                    cur_idx[k]++;
                    break;
                } else {
                    cur_idx[k] = 0;
                    k--;
                }
            }
            if (k < 0) {
                break;
            }
        }
        
        return ret;
    }
};

// recursive
class Solution {
    vector<vector<char> > get_key_mapping() {
        vector<vector<char> > m;
        m.push_back({' '});                 // 0
        m.push_back({});                    // 1
        m.push_back({'a', 'b', 'c'});       // 2
        m.push_back({'d', 'e', 'f'});       // 3
        m.push_back({'g', 'h', 'i'});       // 4
        m.push_back({'j', 'k', 'l'});       // 5
        m.push_back({'m', 'n', 'o'});       // 6
        m.push_back({'p', 'q', 'r', 's'});  // 7
        m.push_back({'t', 'u', 'v'});       // 8
        m.push_back({'w', 'x', 'y', 'z'});  // 9
        
        return m;
    }
    
    void combinations(vector<string> &ret, string &digits, int index, 
                      string &buf, vector<vector<char> > &mapping) {
        if (index < 0) {
            return;
        }
        if (index == digits.size()) {
            ret.push_back(buf);
            return;
        }
        
        int digit = digits[index] - '0';
        vector<char> letters = mapping[digit];
        if (letters.size() == 0) {  // digit == 1
            combinations(ret, digits, index + 1, buf, mapping);
        } else {
            for (int i = 0; i < letters.size(); i++) {
                buf.push_back(letters[i]);
                combinations(ret, digits, index + 1, buf, mapping);
                buf.pop_back();
            }
        }
    }
    
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ret;
        if (digits.size() == 0) {
            return {""};
        }
        
        // build data
        vector<vector<char> > phone_key = get_key_mapping();
        string buf;
        combinations(ret, digits, 0, buf, phone_key);
        
        return ret;
    }
};