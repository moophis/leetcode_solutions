// http://oj.leetcode.com/problems/permutations-ii/

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