// http://oj.leetcode.com/problems/trapping-rain-water/

class Solution {
public:
    int trap(int A[], int n) {
        if (n <= 0) 
            return 0;
            
        stack<pair<int, int> > stk;  // (index, height)
        int start = 0;
        int area = 0;
        
        while (A[start] == 0) // eliminate heading zero column
            start++;
        
        for (int i = start; i < n; i++) {
            if ((i == start && A[i] > A[i+1]) || (i == n - 1 && A[i] >= A[i-1])
                  || A[i] > A[i+1] && A[i] >= A[i-1]) { // find peak
                if (stk.empty()) {
                    stk.push(make_pair(i, A[i]));
                } else {
                    while (!stk.empty()) {
                        bool find_higher = false;
                        int begin = stk.top().first;
                        pair<int, int> cur;
                        
                        // determine which of the two consecutive peak is higher
                        if (stk.top().second <= A[i]) {
                            cur = stk.top();
                            stk.pop();
                        } else {
                            cur = make_pair(i, A[i]);
                            find_higher = true;
                        }
                        for (int j = begin + 1; j < i; j++) {
                            if (cur.second > A[j]) {
                                area += cur.second - A[j];
                                A[j] = cur.second;
                            }
                        }
                        
                        // stop when the heading peak is higher
                        if (find_higher)
                            break;
                    }
                    
                    stk.push(make_pair(i, A[i]));
                } 
            }
        }
        
        return area;
    }
};