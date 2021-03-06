/**
 * Given an array S of n integers, are there elements a, b, c in S 
 * such that a + b + c = 0? Find all unique triplets in the array 
 * which gives the sum of zero.
 *
 * Note:
 * Elements in a triplet (a,b,c) must be in non-descending order. (ie, a �� b �� c)
 * The solution set must not contain duplicate triplets.
 *   For example, given array S = {-1 0 1 2 -1 -4},
 *
 *   A solution set is:
 *   (-1, 0, 1)
 *   (-1, -1, 2)
 */
 
// Without using hash tables
class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> > ret;
        
        if (num.size() < 3) {
            return ret;
        }
        
        sort(num.begin(), num.end());
        
        int last_a = INT_MAX; 
        for (int i = 0; i < num.size() - 2; i++) {
            int j = i + 1;
            int k = num.size() - 1;
            
            // check duplicates
            if (last_a == num[i]) {
                continue;
            } else {
                last_a = num[i];
            }
            
            int last_b = INT_MAX, last_c = INT_MAX;
            while (j < k) {
                int a = num[i], b = num[j], c = num[k];
                
                // check duplicates
                if (last_b == b) {
                    j++;
                    continue;
                } 
                
                if (last_c == c) {
                    k--;
                    continue;
                } 
                
                if (a + b + c == 0) {
                    ret.push_back({a, b, c});
                    j++;
                    last_b = b;
                    k--;
                    last_c = c;
                } else if (a + b + c > 0) {
                    k--;
                    last_c = c;
                } else {
                    j++;
                    last_b = b;
                }
            }
        }
        
        return ret;
    }
};

// using hash table (new, cleaner version)
class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> > ret;
        if (num.size() < 3) {
            return ret;
        }
        
        int last_a = INT_MAX;
        
        sort(num.begin(), num.end());
        for (int i = 0; i < num.size() - 2; i++) {
            int a = num[i];
            int sum = -a;
            int last_b = INT_MAX;
            unordered_set<int> visited;
            
            if (a == last_a) {
                continue;
            } else {
                last_a = num[i];
            }
            
            for (int j = i + 1; j < num.size(); j++) {
                int b = num[j];
                
                if (b == last_b) {
                    continue;
                }
                if (visited.count(sum - b) > 0) {
                    ret.push_back({a, sum - b, b});
                    last_b = b;
                }
                visited.emplace(b);
            }
        }
        
        return ret;
    }
};

// FIXME: using hash tables (legacy)
class Solution {
    /* Two sum problem */
    void two_sum(vector<vector<int> > &ret, vector<int> &num, int addition, 
                 int sum, int begin, int end, bool smaller) {
        unordered_set<int> hs;
        
        for (int i = begin; i < end; ) {
            int n = num[i];
            int t = sum - n;
            
            if (hs.count(t) > 0) {
                if (smaller) {
                    ret.push_back({addition, t, n});
                } else {
                    ret.push_back({t, n, addition});
                }
                hs.erase(t);
                while (num[++i] == n)
                    ;
            } else {
                hs.emplace(num[i++]);
            }
        }
    }
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> > ret;
        int nzbegin = -1;    // non-zero element index beginning
        
        if (num.size() < 3) {  // error checking
            return ret;
        }
        
        // sort the array 
        sort(num.begin(), num.end());
        
        // do some preprocessing work
        if (num[0] < 0) {
            for (int i = 1; i < num.size(); i++) {
                if (num[i] >= 0) {
                    nzbegin = i;
                    break;
                }
            }
            if (nzbegin == -1 || num[num.size() - 1] == 0) {
                return ret;
            }
        } else if (num[0] == 0 && num[1] == 0 && num[2] == 0) {
            return {{0, 0, 0}};
        } else {
            return ret;
        }
        
        // one negative number, two positive numbers
        int last_match = numeric_limits<int>::max();     // sentinel value
        if (nzbegin < num.size() - 1) {
            for (int i = 0; i < nzbegin; i++) {
                if (num[i] == last_match) {
                    continue;
                }
                
                int match = -num[i];
                two_sum(ret, num, num[i], match, nzbegin, num.size(), true);
                last_match = num[i];
            }
        }
        // two negative numbers, one positive number
        last_match = numeric_limits<int>::max();
        if (nzbegin > 1) {
            for (int i = nzbegin; i < num.size(); i++) {
                if (num[i] == last_match) {
                    continue;
                }
                
                int match = -num[i];
                two_sum(ret, num, num[i], match, 0, nzbegin, false);
                last_match = num[i];
            }
        }
        // three zero but has negative numbers
        if (nzbegin < num.size() - 2 && num[nzbegin + 2] == 0) {
            ret.push_back({0, 0, 0});
        }
        
        return ret;
    }
};