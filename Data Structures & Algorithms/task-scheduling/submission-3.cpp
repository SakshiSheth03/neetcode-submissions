class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        for(char ch: tasks) {
            freq[ch-'A']++;
        }
        priority_queue<int> maxHeap;
        for(int f: freq) {
            if(f>0) maxHeap.push(f);
        }
        int time = 0;
        queue<pair<int, int>> q;
        while(!maxHeap.empty() || !q.empty()) {
            time++;
            if(maxHeap.empty()) time = q.front().second;
            else {
                int cnt = maxHeap.top()-1;
                maxHeap.pop();
                if(cnt>0) q.push({cnt, time+n});
            }
            if(!q.empty() && q.front().second == time) {
                maxHeap.push(q.front().first);
                q.pop();
            }
        }
        return time;
    }
};
