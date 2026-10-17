class Solution {
public:
    int jump(vector<int>& nums) {
       int n = nums.size();
       vector<int>dp(n,INT_MAX);
       dp[n-1]=0;
       for(int i=n-2;i>=0;i--){
        int m = min(n-1,i+nums[i]);
        int mini = INT_MAX;
        for(int j=i+1;j<=m;j++){
            mini = min(mini,dp[j]);
        }
        if(mini!=INT_MAX)dp[i]= 1+ mini;
       }
       return dp[0];
    }
};
