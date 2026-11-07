class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        set<int> numSet;
        for(int i=0; i<nums.size(); i++) {
            if(numSet.count(nums[i])) {
                return true;
            } else {
                numSet.insert(nums[i]);
            }
        }
        return false;
    }
};