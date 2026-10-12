class Solution {
public:
    vector<vector<int>>ans;

    void dfs(vector<int>& nums, int i, vector<int>& subset){
        if(i >= nums.size()){
            ans.push_back(subset);
            return;
        }
        subset.push_back(nums[i]);
        dfs(nums,i+1,subset);
        subset.pop_back();
        while(i+1 < nums.size() && nums[i+1]==nums[i])i++;
        dfs(nums,i+1,subset);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        ans.clear();
        vector<int>subset;
        sort(nums.begin(), nums.end());
        dfs(nums,0,subset);
        return ans;
    }
};
