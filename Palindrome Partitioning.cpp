// https://oj.leetcode.com/problems/palindrome-partitioning/

class Solution {
    bool palindrome(string str) {
        size_t len = str.size();
        if (len == 0) {
            return true;
        }
        size_t begin = 0, end = len - 1;
        while (begin < end) {
            if (str[begin] != str[end]) {
                return false;
            } 
            begin++;
            end--;
        }
        
        return true;
    }
    
    void find_partitions(vector<vector<string> > &result, vector<string> &partition, string &s, size_t start) {
        size_t len = s.size();
        if (start == len) {
            result.push_back(partition);
        }
        
        for (size_t i = start; i < len; i++) {
            string sub = s.substr(start, i - start + 1);
            if (palindrome(sub)) {
                partition.push_back(sub);
                find_partitions(result, partition, s, i + 1);
                partition.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s) {
        vector<vector<string> > ret;
        vector<string> partition;
        if (s.size() == 0) {
            return ret;
        }
        
        find_partitions(ret, partition, s, 0);
        return ret;
    }
};