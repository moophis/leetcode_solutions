// http://oj.leetcode.com/problems/largest-rectangle-in-histogram/

// O(n^2) solution with some optimazations.
class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        int max_area = 0;
        
        for (int i = 0; i < height.size(); i++) {
            // reduce duplicates by only taking into account the peak
            // as the right edge
            if (i + 1 < height.size() && height[i] <= height[i + 1])
                    continue;
            int min_height = height[i];
                    
            for (int j = i; j >= 0; j--) {
                min_height = min(height[j], min_height);
                max_area = max(min_height * (i - j + 1), max_area);
            }
        }
        
        return max_area;
    }
};

// O(n) solution, refer to
// http://fisherlei.blogspot.com/2012/12/leetcode-largest-rectangle-in-histogram.html
class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        int max_area = 0;
        stack<int> stk;
        
        height.push_back(0);
        for (int i = 0; i < height.size(); i++) {
            if (stk.empty() || height[i] > height[stk.top()]) {
                stk.push(i);
            } else {
                int j = stk.top();
                stk.pop();
                
                int wid = stk.empty() ? i : i - stk.top() - 1;
                max_area = max(max_area, height[j] * wid);
                i--;
            }
        }
        
        return max_area;
    }
};