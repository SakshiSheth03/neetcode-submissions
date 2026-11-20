class Solution {
private:
    static bool sortOnEndTime(const vector<int>& interval1, const vector<int>& interval2) {
        return interval1[1] < interval2[1];
    } 
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), sortOnEndTime);
        int ans = 0;
        int lastEndTime = intervals[0][1];
        for(int i=1; i<intervals.size(); i++) {
            if(intervals[i][0]<lastEndTime) ans++;
            else lastEndTime = intervals[i][1];
        }
        return ans;
    }
};
