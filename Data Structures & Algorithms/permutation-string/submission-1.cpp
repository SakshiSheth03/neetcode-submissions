class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int s1Len = s1.length(); // window size
        int s2Len = s2.length();
        if(s1Len>s2Len) return false;
        int s1Freq[26] = {0};
        int s2Freq[26] = {0};
        for(int i=0; i<s1Len; i++) {
            s1Freq[s1[i]-'a']++;
            s2Freq[s2[i]-'a']++;
        }
        int match = 0;
        for(int i=0; i<26; i++) {
            if(s1Freq[i]==s2Freq[i]) match++;
        }
        int l = 0, r = s1Len;
        while(r<s2Len) { 
            if(match == 26) return true;
            int idxL = s2[l]-'a';
            s2Freq[idxL]--;
            if(s1Freq[idxL]==s2Freq[idxL]) match++;
            else if(s1Freq[idxL]==s2Freq[idxL]+1) match--;
            int idxR = s2[r]-'a';
            s2Freq[idxR]++;
            if(s1Freq[idxR]==s2Freq[idxR]) match++;
            else if(s1Freq[idxR]==s2Freq[idxR]-1) match--;
            l++;
            r++;
        }
        if(match==26) return true;
        return false;
    }
};
