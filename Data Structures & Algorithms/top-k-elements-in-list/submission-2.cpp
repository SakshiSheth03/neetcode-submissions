class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(int num: nums) {
            mp[num]++;
        }
        vector<vector<int>> arr(nums.size()+1);
        for(auto& pair: mp) {
            arr[pair.second].push_back(pair.first);
        }
        vector<int> ans;
        int cnt = 0;
        for(int i=arr.size()-1; i>=0; i--) {
            if(arr[i].empty()) continue;
            for(int j: arr[i]) {
                ans.push_back(j);
                cnt++;
            }
            if(cnt==k) break;
        }
        return ans;
    }
};