class Solution {
private:
    int expand(string& str, int& n, int left, int right) {
        int count = 0;
        while(left>=0 && right<n && str[left]==str[right]) {
            count++;
            left--;
            right++;
        }
        return count;
    }
public:
    int countSubstrings(string s) {
        int n = s.length();
        int count = 0;
        for(int i=0; i<n; i++) {
            count += expand(s, n, i, i);
            count += expand(s, n, i, i+1);
        }
        return count;
    }
};
