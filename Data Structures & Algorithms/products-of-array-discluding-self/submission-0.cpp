class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product = 1;
        int zero = 0;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i]==0) {
                zero++;
                continue;
            }  
            product *= nums[i];
        }
        cout<<product<<endl;
        vector<int> arr(nums.size(), 0);
        if(zero>1) return arr; 
        for(int i=0; i<nums.size(); i++) {
            if(nums[i]==0) {
                nums[i] = product;
                continue;
            }
            if(zero>0) nums[i] = 0;
            else nums[i] = product / nums[i];
        }
        return nums;
    }
};
