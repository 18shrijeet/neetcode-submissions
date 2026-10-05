class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        // rather than traversing from land cell to treasure chest , we can do a bfs from all the treasure chest cells
        // then every level can be marked as the distance
        int m = grid.size(), n = grid[0].size();
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0)q.push({i,j});
            }
        }
        int level = 0; // first connected will be level +1 = 1, next in queue will be 2 and so on 
        while(!q.empty()){
            int s = q.size();
            for(int i=0;i<s;i++){
                auto [x,y] = q.front();
                q.pop();
                vector<pair<int,int>>dir = {{-1,0},{1,0},{0,-1},{0,1}};
                for(int i=0;i<4;i++){
                    int newX = x + dir[i].first;
                    int newY = y + dir[i].second;
                    if(newX < 0 || newX >= m || newY <0 || newY >=n || grid[newX][newY] != INT_MAX) continue;
                    q.push({newX,newY});
                    grid[newX][newY]=level+1;
                }
            }
            level++;
        }
    }
};
