// https://oj.leetcode.com/problems/maximal-rectangle/

// Find "1" height for each slot, then harness the solution to largest rectangle area 
// to find the maximum area.

class Solution {
    // Refer to: https://oj.leetcode.com/problems/largest-rectangle-in-histogram/
    int largestRectangleArea(vector<int> &height) {
        if (height.size() == 0) {
            return 0;
        }
        
        int max_area = 0;
        stack<int> stk;
        height.push_back(0); 
        for (int i = 0; i < height.size(); ) {
            if (stk.empty() || height[i] > height[stk.top()]) {
                stk.push(i++);
            } else {
                int last = stk.top();
                stk.pop();
                
                int wid = stk.empty() ? i : i - stk.top() - 1;
                int area = wid * height[last];
                max_area = max(max_area, area);
            }
        }
        
        return max_area;
    }
    
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        if (matrix.size() == 0) {
            return 0;
        }
        
        int R = matrix.size();
        int C = matrix[0].size();
        vector<int> heights(C, 0);
        
        // find largest area containing all 1s
        int max_area = 0;
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                heights[j] = (matrix[i][j] == '1') ? heights[j] + 1 : 0;
            }
            int area = largestRectangleArea(heights);
            max_area = max(max_area, area);
        }
        
        return max_area;
    }
};