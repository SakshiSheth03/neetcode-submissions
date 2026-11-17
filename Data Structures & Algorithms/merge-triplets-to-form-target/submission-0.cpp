class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<bool> arr(3, false);
        for(vector<int>& triplet: triplets) {
            if(arr[0] && arr[1] && arr[2]) return true;
            if(triplet[0]>target[0] || triplet[1]>target[1] || triplet[2]>target[2]) continue;
            for(int i=0; i<3; i++) {
                if(triplet[i]==target[i]) arr[i] = true;
            }
        }
        return (arr[0] && arr[1] && arr[2]);
    }
};
