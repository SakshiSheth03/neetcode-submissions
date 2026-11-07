class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> ans;
        for(int i=strs.size()-1; i>=0; i--) {
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            ans[temp].push_back(strs[i]);
        }
        vector<vector<string>> result;
        for(auto& pair: ans) {
            result.push_back(pair.second);
        }
        return result;
    }
};
