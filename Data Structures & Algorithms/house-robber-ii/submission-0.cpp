class Solution {
public:
    int helper(vector<int>& nums, int start, int end){
        int firstMax=0, secondMax=0;
        for(int i=start;i<=end;i++){
            int maxi = max(nums[i]+secondMax, firstMax);
            secondMax=firstMax;
            firstMax=maxi;
        }
        return firstMax;
    }
    int rob(vector<int>& nums) {
        // start with first house i can go till last but 1
        //start with second house i can go till last
        // then choose max of these 2
        int n = nums.size();
        if(n==1)return nums[0];
        return max(helper(nums,1,n-1), helper(nums,0,n-2));
    }
};
