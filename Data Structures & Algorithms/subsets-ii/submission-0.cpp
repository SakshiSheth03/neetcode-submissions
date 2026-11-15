class Solution {
private:
    void findSubsets(vector<int>& nums, vector<vector<int>>& ans, vector<int>& ds, int idx) {
        // at each level, a subset of size idx is added to ans
        // at default null 
        // when idx = 1, a subset of size 1, etc
        ans.push_back(ds);
        // no need of base case as it terminates itself when for loop reaches n 
        for(int i=idx; i<nums.size(); i++) {
            // we won't add duplicate elements
            if(i!=idx && nums[i]==nums[i-1]) continue;
            ds.push_back(nums[i]);
            findSubsets(nums, ans, ds, i+1);
            ds.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // sort so that similar elements stay together
        // we will not add duplicate elemets at all
        sort(nums.begin(), nums.end());
        vector<int> ds;
        vector<vector<int>> ans;
        findSubsets(nums, ans, ds, 0);
        return ans;

        // Brute force is to generate all the subsets, then store it in a set and then convert it into a list of lists
    }
};
