class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;
        int n = heights.size();
        stack<int> stk;
        // expandable rectangle concept
        // using next small elemenet and previous small element

        // area of expandable rectangle is 
        // (nse - pse - 1) * arr[i]
        for(int i=0; i<n; i++) {
            while(!stk.empty() && heights[stk.top()] > heights[i]) {
                int idx = stk.top();
                stk.pop();
                int nse = i, pse = stk.empty()? -1: stk.top();
                maxArea = max(maxArea, (nse-pse-1)*heights[idx]);
            }
            stk.push(i);
        }
        while(!stk.empty()) {
            int ele = stk.top();
            stk.pop();
            int nse = n;
            int pse = stk.empty()? -1: stk.top();
            maxArea = max(maxArea, (nse-pse-1)*heights[ele]);
        }
        return maxArea; 
    }
};
