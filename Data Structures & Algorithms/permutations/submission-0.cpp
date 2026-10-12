class Solution {
public:
    vector<vector<int>>ans;

    void dfs(vector<int>& nums, vector<int>& perm, vector<bool>& visited){
        if(perm.size()== nums.size()){
            ans.push_back(perm);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(visited[i])continue;
            visited[i]=true;
            perm.push_back(nums[i]);
            dfs(nums,perm,visited);
            visited[i]=false;
            perm.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        // base case will be temp vector size == nums.size
        // at every step , we can chose all i's of nums except current i
        // so we can have a visted array , if the number is not visited we can use it 
        // so no need to pass start position , like for subset types either we chose or go for next 
        // for perm wee want all but the current visited one 
        vector<int>perm;
        vector<bool>visited(nums.size(), false);
        dfs(nums, perm, visited);
        return ans;
    }
};
