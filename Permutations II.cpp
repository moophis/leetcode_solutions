// http://oj.leetcode.com/problems/permutations-ii/

// Do not need any additional data structure
class Solution {
    bool contains_dup(vector<int> &num, int from, int to, int value) {
        for (int i = from; i <= to; i++) {
            if (num[i] == value) {
                return true;
            }
        }
        return false;
    }
    
    void do_permute(vector<vector<int> > &ret, vector<int> &buf, vector<int> &num, int left) {
        if (left == 0) {
            ret.push_back(buf);
            return;
        }
        
        for (int i = 0; i < left; i++) {
            if (!contains_dup(num, 0, i - 1, num[i])) {
                buf.push_back(num[i]);
                swap(num[i], num[left - 1]);
                do_permute(ret, buf, num, left - 1);
                swap(num[i], num[left - 1]);
                buf.pop_back();
            }
        }
    }
    
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        vector<vector<int> > ret;
        vector<int> buf;
        int size = num.size();
        if (size <= 0) {
            return ret;
        }
        
        do_permute(ret, buf, num, size);
        
        return ret;
    }
};

// Use additional array to record whether a slot has been used in one function call
class Solution {
    void do_permute(vector<vector<int> > &ret, vector<int> &num, vector<int> &buf, 
                    vector<int> &visited, int begin) {
        if (begin == num.size()) {
            ret.push_back(buf);
            return;
        }
        
        for (int i = 0; i < num.size(); i++) {
            if (visited[i] == 1) {
                // remember we always scan from the beginning
                continue;
            }
            if (i > 0 && num[i] == num[i - 1] && visited[i - 1] == 0) {
                continue;
            }
            
            int t = num[i];
            
            buf.push_back(t);
            visited[i] = 1;
            do_permute(ret, num, buf, visited, begin + 1);
            visited[i] = 0;
            buf.pop_back();
        }
    }
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        if (num.size() == 0) {
            return {{}};
        }
        
        vector<vector<int> > ret;
        vector<int> buf;
        vector<int> visited(num.size(), 0);
        
        sort(num.begin(), num.end());
        do_permute(ret, num, buf, visited, 0);
        
        return ret;
    }
};