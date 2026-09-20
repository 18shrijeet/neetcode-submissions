class Solution {
public:
    int trap(vector<int>& height) {
        // At every step , we need to check how much water can be stored at each index which will be 
        // minimum of left, right (both greater than current) - current index 
        // example 2 0 3 , min(2,3) = 2 - cuur(0) = 2 {both 2 and 3 greatre than curr 0}
        // so we can store 2 arrays prefix kind of , greatest in left and greatest in right , then calculate for every i 
        // then sum all of it , 3*O(n) = O(n)

        int n = height.size();
        vector<int>left(n,0);
        vector<int>right(n,0);
        left[0]= height[0];
        right[n-1]= height[n-1];
        for(int i=1;i<n;i++)
        {
            left[i] = max(left[i-1],height[i]);
        }
        for(int i=n-2;i>=0;i--)
        {
            right[i]= max(right[i+1], height[i]);
        }
        int area = 0;
        for(int i=0;i<n;i++)
        {
            height[i] = min(left[i],right[i]) - height[i];
            area+=height[i];
        }
        return area;
    }
};
