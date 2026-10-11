class Solution {
public:
    void dfs(vector<int>& nums, vector<int>& combination, int i, int sum, vector<vector<int>>& ans, int target){
        if(i>=nums.size() || sum>= target){
            if(sum == target){
                ans.push_back(combination);
            }
            return;
        }
        // include nums[i] -> this also will branch for same nums[i] repeating too
        combination.push_back(nums[i]);
        dfs(nums,combination,i,sum+nums[i],ans,target);

        combination.pop_back();
        dfs(nums,combination,i+1,sum,ans,target);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        // chose a no or do NOT chose a number
        // base case:
            // if the sum == target append to ans, if sum > target return from dfs call
        vector<vector<int>> ans;
        vector<int>combination;
        dfs(nums, combination, 0, 0, ans, target);
        return ans;
    }
};
