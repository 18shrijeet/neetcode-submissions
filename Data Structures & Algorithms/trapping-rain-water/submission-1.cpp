class Solution {
public:
    int trap(vector<int>& height) {
        // At any point shorter wall decides if water can be trapped by this much limit 
        // so we use 2 pointers 
        // at any point we calculate leftmax till the point , and if leftmax is smaller than rightmax left++ else right--
        // and we add leftmax-height[i] or rightmax-height[i] to result
        // O(n) time + O(1) space

        int n = height.size();
        int i=0, j = n-1;
        int leftmax = height[i], rightmax= height[j];
        int res = 0;
        while(i<j)
        {
            if(leftmax < rightmax){
                i++;
                leftmax= max(leftmax,height[i]);
                res += (leftmax-height[i]);
                
            }
            else{
                j--;
                rightmax= max(rightmax,height[j]);
                res += (rightmax-height[j]);
            }
        }
        return res;
    }
};
