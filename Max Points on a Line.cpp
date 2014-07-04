// https://oj.leetcode.com/problems/max-points-on-a-line/

/*
 * Take every point as a hub point and find points on
 * lines that go through the given hub point. And then
 * find the maximum among all possibilities.
 *
 * Note: Be careful when several points overlap. 
 */

 /**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
    const double EPS = 1e-3;
    
public:
    int maxPoints(vector<Point> &points) {
        int max_points = 0;
        size_t size = points.size();
        if (size <= 2) {
            return (int) size;
        }
        
        unordered_map<double, int> slope_cnt;
        for (size_t i = 0; i < size; i++) {
            int same_pts = 1;
            
            slope_cnt.clear();
            for (size_t j = i+1; j < size; j++) {
                double slope = numeric_limits<double>::max();
                double dx = static_cast<double>(points[i].x - points[j].x);
                double dy = static_cast<double>(points[i].y - points[j].y);
                
                if (abs(dx) > EPS) {
                    slope = dy / dx;
                } else if (abs(dy) <= EPS) {
                    // two points overlap
                    same_pts++;
                    continue;
                }
                if (slope_cnt.count(slope) == 0) {
                    slope_cnt.emplace(slope, 1);
                } else {
                    slope_cnt[slope]++;
                }
            }
            
            max_points = max(max_points, same_pts);
            for (auto it = slope_cnt.begin(); it != slope_cnt.end(); ++it) {
                max_points = max(max_points, it->second + same_pts);
            }
        }
        
        return max_points;
    }
};