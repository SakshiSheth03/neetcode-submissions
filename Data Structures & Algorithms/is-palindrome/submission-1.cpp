class Solution {
public:
    bool isPalindrome(string s) {
        if(s.length()==1) { return true; }
        int p1=0, p2=s.length()-1;
        while(p1<p2) {
            if(!isalnum(s[p1])) { p1++; continue; }
            if(!isalnum(s[p2])) { p2--; continue; }
            if(tolower(s[p2])!=tolower(s[p1])) { return false; }
            p1++; p2--;
        }
        return true;
    }
};