class Solution {
public:

    string encode(vector<string>& strs) {
        string ans = "";
        for(int i=0; i<strs.size(); i++) {
            ans += to_string(strs[i].length());
            ans += "#";
            ans += strs[i];
        }
        return ans;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        int n = s.length();
        int i = 0;
        while(i<n) {
            string lenOfStr = "";
            while(s[i]!='#') {
                lenOfStr += s[i];
                i++;
            }
            i++;
            int len = stoi(lenOfStr);
            ans.push_back(s.substr(i, len));
            i+=len;
        }
        return ans;
    }
};
