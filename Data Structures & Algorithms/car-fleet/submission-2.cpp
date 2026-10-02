class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>>p;
        for(int i = 0;i<speed.size();i++){
            p.push_back({position[i],speed[i]});
        }
        sort(p.rbegin(),p.rend());
        double ptime = (double)(target-p[0].first)/p[0].second;
        int fleets=1;
        for(int i = 1;i<speed.size();i++){
            double time = (double)(target-p[i].first)/p[i].second;
            if(time > ptime){
                fleets++;
                ptime=time;
            }
        }
        return fleets;
    }
};