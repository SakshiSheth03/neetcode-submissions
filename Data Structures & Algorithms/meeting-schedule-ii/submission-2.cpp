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
        vector<int> start;
        vector<int> end;
        for(int i=0; i<n; i++) {
            start.push_back(intervals[i].start);
            end.push_back(intervals[i].end);
        }
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        int s=0, e=0;
        int res=0, count=0;
        while(s<n) {
            if(end[e]<=start[s]) {
                e++;
                count--;
            } else {
                s++;
                count++;
            }
            res = max(res, count);
        }
        return res;
    }
};
