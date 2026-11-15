class Solution {
private:
    void generate(vector<int>& nums, vector<vector<int>>& ans, int idx) {
        int n = nums.size();
        if(idx==n) {
            ans.push_back(nums);
            return;
        }
        for(int i=idx; i<n; i++) {
            swap(nums[i], nums[idx]);
            generate(nums, ans, idx+1);
            swap(nums[i], nums[idx]);
        }
    } 
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        generate(nums, ans, 0);
        return ans;
    }
};
