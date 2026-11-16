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
        int maxCount = 0;
        for(int f: freq) {
            if(f==maxi) maxCount++;
        }
        // maxi - 1 = no of windows A will create
        // (A _ _) (A _ _) (A _ _) A
        // n is ideal spaces in between so n + 1 = window size
        // Suppose A and B has same freq:
        // (A B _) (A B _) (A B _) [A B]
        // [A B] -> maxCount
        int time = (maxi-1)*(n+1) + maxCount;
        return max(total, time);
    }
};
