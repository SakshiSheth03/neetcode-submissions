class Solution {
public:
    string minWindow(string s, string t) {
        int sLen = s.length(), tLen = t.length();
        if(tLen>sLen) return "";
        int freq[256] = {0};
        for(int i=0; i<tLen; i++) {
            freq[t[i]]++;
        }
        if(sLen == tLen) {
            for(int i=0; i<sLen; i++) {
                freq[s[i]]--;
            }
            for(int& f: freq) {
                if(f!=0) return "";
            }
            return s;
        }
        int l=0, r=0;
        int count = 0;
        int minLen = INT_MAX, sIdx = -1;
        while(r<sLen) {
            if(freq[s[r]]>0) count++; 
            freq[s[r]]--;
            while(count==tLen) {
                if(r-l+1<minLen) {
                    minLen = r-l+1;
                    sIdx = l;
                }
                freq[s[l]]++;
                if(freq[s[l]]>0) count--;  
                l++;
            } 
            r++;
        }
        return sIdx == -1? "" : s.substr(sIdx, minLen);
    }
};