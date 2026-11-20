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
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        int n = intervals.size();
        if(n==0) return 0;
        vector<int> lastEndTime;
        sort(intervals.begin(), intervals.end(), [](Interval& a, Interval& b) {
            return a.start<b.start;
        });
        lastEndTime.push_back(intervals[0].end);
        for(int i=1; i<n; i++) {
            int j=0;
            while(j<lastEndTime.size()) {
                if(intervals[i].start >= lastEndTime[j]) {
                    lastEndTime[j] = intervals[i].end;
                    break;
                }
                j++;
            }
            if(j==lastEndTime.size()) {
                lastEndTime.push_back(intervals[i].end);
            }
        }
        return lastEndTime.size();
    }
};
