class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>>>maxD;
        vector<vector<int>>res;
        for(int i=0;i<points.size();i++){
            int x = points[i][0], y = points[i][1];
            maxD.push({x*x+y*y, i});
            if(maxD.size() > k) maxD.pop();
        }
        while(!maxD.empty()){
            res.push_back(points[maxD.top().second]);
            maxD.pop();
        }
        return res;
    }
};
