class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i=0;
        while(i<nums.size()) {
            for(int j=i+1; j<nums.size(); j++) {
                if(nums[i]+nums[j]==target) {
                    return {i, j};
                }
            }
            i++;
        }
        return {};
    }
};
