class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>u(n);
        for(int x: nums)
        {
            if(u[x] > 0) return true;
            else u[x]++;
        }
        return false;
    }
};