class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int p1=0, p2=0;
       int len = prices.size();
       int maxi = 0;
       while(p1<len && p2<len) {
        int diff = prices[p2]-prices[p1];
        if(diff<0) {
            p1 = p2;
            p2++;
        } else if(diff == 0) {
            p2++;
        } else {
            p2++;
            maxi = max(maxi, diff);
        }
       } 
       return maxi;
    }
};
