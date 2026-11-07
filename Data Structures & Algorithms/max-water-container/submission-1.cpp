class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxArea = INT_MIN;
        int i=0, j=heights.size()-1;
        while(i<j) {
            int area = (j-i)*min(heights[i], heights[j]);
            if(area>maxArea) maxArea = area;
            if(heights[i]<heights[j]) i++;
            else j--;
        }
        return maxArea;
    }
};
