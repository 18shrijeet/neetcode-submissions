class Solution {
public:
    void bk(vector<int>& nums, vector<vector<int>>& ans, int n, int i, vector<int>& temp){        
        if(i==n){
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[i]);
        bk(nums,ans,n, i+1, temp);
        temp.pop_back();
        bk(nums,ans,n, i+1, temp);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int> temp;
        int n = nums.size();
        bk(nums,ans,n, 0, temp);
        return ans;
    }
};
