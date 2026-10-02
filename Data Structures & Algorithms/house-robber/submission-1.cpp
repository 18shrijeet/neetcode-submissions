class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1)return nums[0];
        if(n<3)return max(nums[0],nums[1]);
        vector<int>maxi(n+1,0);
        maxi[0]=nums[0], maxi[1]= max(nums[0],nums[1]);
        for(int i=2;i<n;i++){
            maxi[i]= max(maxi[i-1], maxi[i-2]+nums[i]);
        }
        return maxi[n-1];
    }
};
