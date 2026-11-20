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
        int n=intervals.size();
        if(n==0) return 0;
        sort(intervals.begin(), intervals.end(), [](Interval& a, Interval& b) {
            return a.start < b.start;
        });
        priority_queue<int, vector<int>, greater<int>> minHeap;
        int i=0;
        while(i<n) {
            if(!minHeap.empty() && minHeap.top()<=intervals[i].start) {
                minHeap.pop();
            }
            minHeap.push(intervals[i].end);
            i++;
        }
        return minHeap.size();
    }
};
