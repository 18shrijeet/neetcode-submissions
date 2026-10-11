class Solution {
public:
    vector<vector<int>> ans;

    void dfs(vector<int>& candidates, vector<int>& comb, int i, int sum, int target){
        if(i>=candidates.size() || sum >=target){
            if(sum==target){
                ans.push_back(comb);
            }
            return;
        }
        // include curent candidate only once
        comb.push_back(candidates[i]);
        dfs(candidates, comb, i+1, sum+candidates[i], target);
        comb.pop_back();
        // do Not include current , but
        // since no DUPLICATES => skip all duplicates
        while(i<candidates.size()-1 && candidates[i] == candidates[i+1])i++;
        dfs(candidates, comb, i+1, sum, target);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // We can sort the array and whenever we want to add the next i we will skip the index till the duplicates are removed
        sort(candidates.begin(), candidates.end());
        vector<int> comb;
        dfs(candidates, comb, 0, 0, target);
        return ans;
    }
};
