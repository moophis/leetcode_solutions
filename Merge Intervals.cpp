// https://oj.leetcode.com/problems/merge-intervals/

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

// O(nlogn) solution
class Solution {
public:
    struct IntervalCompare {
        inline bool operator()(const Interval &lhs, const Interval &rhs) {
            return (lhs.start < rhs.start);
        }
    };

    vector<Interval> merge(vector<Interval> &intervals) {
        vector<Interval> ret;
        if (intervals.size() == 0) {
            return ret; 
        }
        
        sort(intervals.begin(), intervals.end(), IntervalCompare());
        
        Interval cur = intervals[0];
        for (auto it = intervals.begin(); it != intervals.end(); ++it) {
            if (cur.end < it->start) {
                ret.push_back(cur);
                cur = *it;
            } else {
                cur.start = min(cur.start, it->start);
                cur.end = max(cur.end, it->end);
            }
        }
        ret.push_back(cur);
        
        return ret;
    }
};

// Naive O(n^2) solution
class Solution {
    // see: https://oj.leetcode.com/problems/insert-interval/
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
    
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        vector<Interval> ret;
        
        if (intervals.size() < 2) {
            return intervals;
        }
        
        for (int i = 0; i < intervals.size(); i++) {
            ret = insert(ret, intervals[i]);
        }
        
        return ret;
    }
};