class Solution {
public:
    bool isPalindrome(string s) {
        if(s.length()==1) {
            return true;
        }
        string str;
        for(int i=0; i<s.length(); i++) {
            if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z') || (s[i]>='0' && s[i]<='9')) {
                if(isdigit(s[i])) {
                    str+=s[i];
                    continue;
                }
                str+=tolower(s[i]);
            }
        }
        int n = str.length();
        for(int i=0; i<n/2; i++) {
            if(str[i]!=str[n-i-1]) {
                return false;
            }
        }
        return true;
    }
};