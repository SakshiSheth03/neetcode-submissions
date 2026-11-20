class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        vector<int> copyQueries = queries;
        sort(copyQueries.begin(), copyQueries.end());
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
            return a[0]==b[0]? a[1]<b[1]: a[0]<b[0];
        });
        int n = intervals.size();
        auto cmp = [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.first>b.first || (a.first==b.first && a.second>b.second);
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> minHeap(cmp);
        unordered_map<int, int> mp;
        int i=0;
        for(int& query: copyQueries) {
            while(i<n && intervals[i][0]<=query) {
                minHeap.push({intervals[i][1]-intervals[i][0]+1,intervals[i][1]});
                i++;
            }
            while(!minHeap.empty() && minHeap.top().second<query) {
                minHeap.pop();
            }
            mp[query] = minHeap.empty()? -1: minHeap.top().first;
        }
        vector<int> res;
        for(int& query: queries) {
            res.push_back(mp[query]);
        }
        return res;
    }
};
