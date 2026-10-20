class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // we can have a maxSoFar if it goes < 0 , then reset it to 0 and get max ans out of it every time
        int ans = nums[0], maxSoFar = nums[0];
        for(int i=1;i<nums.size();i++){
            maxSoFar = max(nums[i], maxSoFar+nums[i]);
            ans = max(ans,maxSoFar);
            
        }
        return ans;
    }
};
