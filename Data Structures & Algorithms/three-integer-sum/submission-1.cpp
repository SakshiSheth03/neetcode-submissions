class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int i=0;
        while(i<nums.size()-2) {
            if(nums[i]>0) break;
            while(nums[i]==nums[i-1] && i>0 && i<nums.size()-2) i++;
            int j=i+1, k=nums.size()-1;
            while(j<k) {
                int sum = nums[i] + nums[j] + nums[k];
                if(sum>0) k--;
                else if(sum<0) j++;
                else {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                    while(j<k && nums[j]==nums[j-1]) j++;
                }
            }
            i++;
        }
        return ans;
    }
};
