class Solution {
private:
    void checkSum(vector<int>& candidates, int target, vector<vector<int>>& res, int idx, int& n, vector<int>& arr) {
        if(target==0) {
            res.push_back(arr);
            return;
        }
        for(int i=idx; i<n; i++) {
            if(i>idx && candidates[i] == candidates[i-1]) continue;
            if(candidates[i]>target) break;
            arr.push_back(candidates[i]);
            checkSum(candidates, target-candidates[i], res, i+1, n, arr);
            arr.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        int n = candidates.size();
        vector<vector<int>> res;
        vector<int> arr;
        checkSum(candidates, target, res, 0, n, arr);
        return res;
    }
};
