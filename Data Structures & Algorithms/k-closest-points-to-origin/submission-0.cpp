class Solution {
private:
    double distFromOrigin(int a, int b) {
        return sqrt(a*a + b*b);
    }
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double, vector<int>>> pq;
        for(vector<int>& point: points) {
            pq.push({distFromOrigin(point[0], point[1]), {point[0], point[1]}});
            if(pq.size()>k) pq.pop();
        }
        vector<vector<int>> ans;
        int cnt = k;
        while(cnt>0) { 
            ans.push_back(pq.top().second);
            pq.pop();
            cnt--;
        }
        return ans;
    }
};
