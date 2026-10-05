class Solution {
public:
    int dfs(vector<vector<int>>& grid, int i, int j, int& count){
        if(i<0 || j<0 || i>= grid.size() || j >= grid[0].size() || grid[i][j]==0) return 0;
        count++;
        grid[i][j]=0;
        dfs(grid,i+1,j,count);
        dfs(grid,i-1,j,count);
        dfs(grid,i,j+1, count);
        dfs(grid,i,j-1, count);
        return count;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int maxi = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1){
                    int count = 0;
                    int res = dfs(grid,i,j,count);
                    maxi = max(maxi,count);
                }
            }
        }
        return maxi;
    }
};
