class Solution {
private:
    void checkSum(vector<int>& candidates, int target, vector<vector<int>>& res, int idx, int& n, vector<int> arr) {
        if(target==0) {
            res.push_back(arr);
            return;
        } 
        if(idx==n) return;
        if(candidates[idx]<=target) {
            arr.push_back(candidates[idx]);
            checkSum(candidates, target-candidates[idx], res, idx+1, n, arr);
            arr.pop_back();
        }
        int nextIdx = idx + 1;

        while(nextIdx < n && candidates[nextIdx] == candidates[idx]) {
            nextIdx++;
        }
        checkSum(candidates, target, res, nextIdx, n, arr);
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        int n = candidates.size();
        vector<vector<int>> res;
        checkSum(candidates, target, res, 0, n, {});
        return res;
    }
};
