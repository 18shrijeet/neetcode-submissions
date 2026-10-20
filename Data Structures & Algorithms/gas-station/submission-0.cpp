class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas = 0;
        int tankSize = 0;
        int start = 0;
        for(int i=0;i<gas.size();i++){
            totalGas += gas[i] - cost[i];
            tankSize  += gas[i] - cost[i];
            if(tankSize < 0){
                start = i+1;
                tankSize = 0;
            };
        }
        if(totalGas < 0) return -1;
        return start;
    }
};
