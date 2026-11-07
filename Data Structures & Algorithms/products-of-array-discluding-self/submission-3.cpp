class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);
        
        for(int i=1; i<n; i++) 
            ans[i] = ans[i-1] * nums[i-1];
        
        int sufProduct = 1;
        for(int i=n-2; i>=0; i--) {
            sufProduct *= nums[i+1];
            ans[i] *= sufProduct;
        }

        return ans;
    }
};