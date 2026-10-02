class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int>mini(cost.size()+1,0);
        for(int i=2;i<=cost.size();i++){
            mini[i]=min(mini[i-1]+cost[i-1], mini[i-2]+cost[i-2]);
        }
        return mini[cost.size()];
    }
};
