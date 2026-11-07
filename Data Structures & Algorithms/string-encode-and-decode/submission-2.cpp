class Solution {
public:

    string encode(vector<string>& strs) {
        string ans = "";
        for(int i=0; i<strs.size(); i++) {
            ans+=strs[i];
            ans+="#*#";
        }
        return ans;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        string temp;
        int n = s.length();
        for(int i=0; i<n; i++) {
            if(s[i]=='#') {
                if(i<(n-2) && s[i+1]=='*' && s[i+2]=='#') {
                    ans.push_back(temp);
                    temp = "";
                    i+=2;
                } else {
                    temp += s[i];
                }
            } else {
                temp += s[i];
            }
        }
        return ans;
    }
};
