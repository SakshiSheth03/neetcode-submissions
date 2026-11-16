class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int i=0, n = nums.size();
        int maxi = INT_MIN;
        int sum = 0;
        while(i<n) {
            sum += nums[i];
            maxi = max(maxi, sum);
            if(sum<0) sum = 0;
            i++;
        }
        return maxi;
    }
};
