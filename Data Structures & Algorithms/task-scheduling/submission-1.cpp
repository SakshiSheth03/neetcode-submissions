class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        int maxi = 0;
        int total = tasks.size();
        for(char ch: tasks) {
            freq[ch-'A']++;
            maxi = max(maxi, freq[ch-'A']);
        }
        int ideal = (maxi-1)*n;
        for(int f: freq) {
            // fill all the ideal slots
            // Suppose A = 4 and also B =4
            // We can't fill 4 ideal spots in 3 windows with 4 Bs
            // min is to check for elements having same freq as A
            ideal -= min(maxi-1, f);
            // if ideal < 0 means no ideal spots remains
        }
        ideal += (maxi-1); // corrected
        return total + max(0, ideal);
    }
};
