class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        if(nums.size()==1) return 1;
        int maxCnt = 1, cnt = 1, prevNum = INT_MAX;
        set<int> ans;
        for(int i=0; i<nums.size(); i++) {
            ans.insert(nums[i]);
        }
        vector<int> arr;
        while(!ans.empty()) {
            arr.push_back(*ans.begin());
            ans.erase(ans.begin());
        }
        for(int i=1; i<arr.size(); i++) {
            if(arr[i]==arr[i-1]+1) {
                cnt++;
            } else {
                cnt = 1;
            }
            maxCnt = max(cnt, maxCnt);
        }
        return maxCnt;
    }
};
