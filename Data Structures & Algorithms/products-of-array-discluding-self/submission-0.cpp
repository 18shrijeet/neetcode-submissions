class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>leftprefix(n,1);
        for(int i=1;i<n;i++)
        {
            leftprefix[i]= nums[i-1]*leftprefix[i-1];
        }
        int rightProduct = 1;
        for(int i=n-1;i>=0;i--)
        {
            leftprefix[i]*=rightProduct;
            rightProduct*=nums[i];
        }
        return leftprefix;
    }
};
