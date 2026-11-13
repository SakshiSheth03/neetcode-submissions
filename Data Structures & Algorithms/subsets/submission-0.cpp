class Solution {
private:
    void generate(vector<int>& nums, vector<vector<int>>& arr, int i, int& n, vector<int> elements) {
        if(i==n) {
            arr.push_back(elements);
            return;
        }    
        elements.push_back(nums[i]);
        generate(nums, arr, i+1, n, elements);
        elements.pop_back();
        generate(nums, arr, i+1, n, elements);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> arr;
        int n = nums.size();
        generate(nums, arr, 0, n, {});
        return arr;
    }
};
