class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> lastIdx;
        int n = s.size();
        for(int i=0; i<n; i++) {
            lastIdx[s[i]] = i;
        }
        vector<int> ans;
        int windowSize=0, end=0;
        for(int i=0; i<n; i++) {
            windowSize++;
            end = max(end, lastIdx[s[i]]);
            if(i==end) {
                ans.push_back(windowSize);
                windowSize = 0;
            }
        }
        return ans;
    }
};
