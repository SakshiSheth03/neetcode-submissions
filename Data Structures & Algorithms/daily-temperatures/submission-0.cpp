class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>> stk;
        int n = temperatures.size();
        vector<int> ans(n, 0);
        for(int i=0; i<n; i++) {
            int temp = temperatures[i];
            while(!stk.empty() && stk.top().first<temp) {
                int temp = stk.top().first;
                int idx = stk.top().second;
                stk.pop();
                ans[idx] = i-idx;
            }
            stk.push({temp, i});
        }
        return ans;
    }
};
