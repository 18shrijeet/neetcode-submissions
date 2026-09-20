class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int i=0,j=n-1;
        int maxA = 0;
        while(i<j)
        {
            int height = min(heights[i],heights[j]);
            maxA = max(maxA,height*(j-i));
            while(i<j && heights[i] <= height)i++;
            while(i<j && heights[j] <= height)j--;
        }
        return maxA;
    }
};
