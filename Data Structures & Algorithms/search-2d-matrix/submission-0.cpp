class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        if(target<matrix[0][0] || target>matrix[rows-1][cols-1]) return false;
        int low=0, high = rows-1;
        while(low<=high) {
            int midRow = (low+high)/2;
            if(target>=matrix[midRow][0] && target<=matrix[midRow][cols-1]) {
                int left=0, right=cols-1;
                while(left<=right) {
                    int midCol = (left+right)/2;
                    if(matrix[midRow][midCol]==target) return true;
                    else if(matrix[midRow][midCol]>target) right = midCol-1;
                    else left = midCol+1;
                }                
                return false;
            }  
            else if(target<matrix[midRow][0]) high = midRow-1;
            else low = midRow+1;
        }
        return false;
    }
};
