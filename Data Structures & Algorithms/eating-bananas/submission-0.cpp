class Solution {
private:
    int maxElement(vector<int>& arr, int n) {
        int maxi = INT_MIN;
        for(int i=0; i<n; i++) {
            maxi = max(maxi, arr[i]);
        }    
        return maxi;
    }    
    bool canFinish(vector<int>& piles, int x, int n, int h) {
        int hrs = 0;
        for(int j=0; j<n; j++) {
            hrs += ceil((double) piles[j]/ (double) x);
            if(hrs > h) return false;
        }
        return true;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int low = 1, high = maxElement(piles, n);
        while(low <= high) {
            int mid = (low + high) / 2;
            if(canFinish(piles, mid, n, h)) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};