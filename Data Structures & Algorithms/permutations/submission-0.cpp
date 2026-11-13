class Solution {
private:
    void recrPerm(vector<int>& nums, vector<vector<int>>& res, int& n, vector<int>& arr, vector<bool>& freq) {
        if(arr.size()==n) {
            res.push_back(arr);
            return;
        }
        for(int i=0; i<n; i++) {
            if(freq[i]==true) continue;
            arr.push_back(nums[i]);
            freq[i] = true;
            recrPerm(nums, res, n, arr, freq);
            arr.pop_back();
            freq[i] = false;
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        vector<int> arr;
        vector<bool> freq(n);
        recrPerm(nums, res, n, arr, freq);
        return res;
    }
};
