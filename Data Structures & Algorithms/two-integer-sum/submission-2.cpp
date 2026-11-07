class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> idxMap;
        for(int i=0; i<nums.size(); i++) {
            int diff = target - nums[i];
            if(idxMap.count(diff)) {
                return {idxMap[diff], i};
            } else {
                idxMap.insert({nums[i], i});
            }
        }
        return {};
    }
};
