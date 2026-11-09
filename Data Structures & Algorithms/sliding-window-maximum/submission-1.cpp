class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int len = nums.size();
        vector<int> ans;
        deque<int> dq;
        for(int i=0; i<len; i++) {
            // first check if any element is outside the current window -> remove from front
            if(!dq.empty() && dq.front()<=i-k) {
                dq.pop_front();
            }
            // remove any elements lesser than current ele starting from back of deque
            while(!dq.empty() && nums[dq.back()]<=nums[i]) {
                dq.pop_back();
            }
            // push the curr always
            dq.push_back(i);
            // if we have reached a point where a full window can is traversed then start adding it to ans
            if(i>=k-1) ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};
