class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0, r=0;
        int len = s.length();
        int arr[26] = {0};
        int maxFreq = 0;
        int maxLen = 0;
        while(r<len) {
            arr[s[r]-'A']++;
            maxFreq = max(maxFreq, arr[s[r]-'A']);
            int subStrLen = r - l + 1;
            if((subStrLen - maxFreq)>k) {
                arr[s[l]-'A']--;
                maxFreq = 0;
                for(int& c: arr) {
                    maxFreq = max(maxFreq, c);
                }
                subStrLen--;
                l++;
            }
            if((subStrLen-maxFreq)<=k) {
                maxLen = max(subStrLen, maxLen);
            }
            r++;
        }
        return maxLen;
    }
};
