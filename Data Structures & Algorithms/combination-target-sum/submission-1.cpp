class Solution {
private:
    void checkSum(vector<int>& nums, int target, vector<vector<int>>& res, int idx, int& n, vector<int> arr) {
        if(idx==n) {
            if(target==0) res.push_back(arr);
            return;
        }
        if(nums[idx]<=target) {
            arr.push_back(nums[idx]);
            checkSum(nums, target-nums[idx], res, idx, n, arr);
            arr.pop_back();
        }
        checkSum(nums, target, res, idx+1, n, arr);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        int n = nums.size();
        checkSum(nums, target, res, 0, n, {});
        return res;
    }
};
