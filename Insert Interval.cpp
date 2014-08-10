// https://oj.leetcode.com/problems/insert-interval/

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval> ret;
        size_t size = intervals.size();
        if (size == 0) {
            ret.push_back(newInterval);
            return ret;
        }
        
        bool inserted = false;
        int start = newInterval.start, end = newInterval.end;
        if (start > end) {
            return intervals;
        }
        for (size_t i = 0; i < size; i++) {
            if (inserted || start > intervals[i].end) {
                ret.push_back(intervals[i]);
                continue;
            }
            if (end < intervals[i].start) {
                Interval intval(start, end);
                ret.push_back(intval);
                ret.push_back(intervals[i]);
                inserted = true;
            } else {
                start = min(start, intervals[i].start);
                end = max(end, intervals[i].end);
            }
        }
        if (!inserted) {
            Interval intval(start, end);
            ret.push_back(intval);
        }
        
        return ret;
    }
};