// https://oj.leetcode.com/problems/container-with-most-water/

class Solution {
public:
    int maxArea(vector<int> &height) {
        if (height.size() < 2) {
            return 0;
        }
        
        int i = 0, j = height.size() - 1;
        int area = 0;
        while (i < j) {
        	// Since the bottle-neck of the area is the shorter
        	// line, we have to change this shorter line in order
        	// to find larger area.
            if (height[i] >= height[j]) {
                area = max(area, height[j]*(j-i));
                j--;
            } else {
                area = max(area, height[i]*(j-i));
                i++;
            } 
        }
        
        return area;
    }
};