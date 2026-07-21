class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int,int>values;
        values[nums[0]]=1;
        for(int i=1;i<n;i++)
        {
            if(values.find(target-nums[i]) != values.end())
            {
                return {values[target-nums[i]]-1, i};
            }
            values[nums[i]]=i+1;
        }
        return {};
    }
};
