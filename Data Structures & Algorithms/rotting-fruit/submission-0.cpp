class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // we can use multi node bfs from all the rotten fruits , at each minute = each level bfs all healthy fruits will be rotten 
        // we will keep an initial count of healthy fruits 
        // while bfs if rotten comes across health fruit and we make it 2 , subtract from healthy count
        // at end if health_count > 0 ? -1 : level(minutes)

        ///// Use multi-rotten fruit nodes bfs /////
        
        int m = grid.size(), n=grid[0].size();
        int healthy = 0;

        queue<pair<int,int>>q;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1)healthy++;
                else if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        vector<vector<int>> d = {{-1,0},{1,0},{0,1},{0,-1}};
        int level = 0; // minutes
        while(!q.empty() && healthy > 0){
            int s = q.size();
            for(int i=0;i<s;i++){
                auto [x,y]= q.front(); 
                q.pop();
                for(int j=0;j<4;j++){
                    int nX = x+d[j][0];
                    int nY = y + d[j][1];
                    if(nX <0 || nX >=m || nY <0 || nY >=n || grid[nX][nY] != 1)continue;
                    healthy--;
                    grid[nX][nY]=2;
                    q.push({nX,nY});
                }
            }
            level++;
        }
        return healthy > 0 ? -1 : level;
    }
};
