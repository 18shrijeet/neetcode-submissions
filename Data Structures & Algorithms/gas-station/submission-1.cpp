class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if (accumulate(gas.begin(), gas.end(), 0) <
            accumulate(cost.begin(), cost.end(), 0)) {
            return -1;
        }
        int tankSize = 0;
        int start = 0;
        for(int i=0;i<gas.size();i++){
            tankSize  += gas[i] - cost[i];
            if(tankSize < 0){
                start = i+1;
                tankSize = 0;
            };
        }
        if(tankSize < 0) return -1;
        return start;
    }
};
