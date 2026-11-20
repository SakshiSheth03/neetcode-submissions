/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
private:
    static bool sortOnEndTime(const Interval& int1, const Interval& int2) {
        return int1.end < int2.end;
    }
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        int n = intervals.size();
        if(n==0) return true;
        sort(intervals.begin(), intervals.end(), sortOnEndTime);
        int lastEndTime = intervals[0].end;
        for(int i=1; i<intervals.size(); i++) {
            if(intervals[i].start<lastEndTime) return false;
            else lastEndTime = intervals[i].end;
        }
        return true;
    }
};
