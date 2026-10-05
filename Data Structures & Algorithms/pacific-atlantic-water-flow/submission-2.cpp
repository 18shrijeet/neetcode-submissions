class Solution {
public:
    vector<pair<int,int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        // for a cell to reach its water to pcaific and atlantic
        /*
        Pacific = left + top { row=0 , column = 0}
        Atlantic = bottom + right { row = m , column = n}
        so to reach both then  , it has to reach one of these 
        {0,n} , {m,0} 
        so from these 4 sides  if we start bfs/dfs and if those connected nodes have water level > current level 
        first start with one lets say {0,n} , if they are greater than current levels water , push them into a set lets say 
        and then same from other node 
        then intersection of those 2 sets will be ans ? 

        rather than sets , we keep 2 vectors for 2 grids for pacific and atlantic and if i,j of both matrix is 1 then thats one of our ans
        */
        int r = heights.size(), c = heights[0].size();
        vector<vector<int>>res;

        vector<vector<bool>>pac(r, vector<bool>(c,false));
        vector<vector<bool>>atl(r, vector<bool>(c,false));
        
        // for every rows 
        //first col = pacific , last column = atlantic , start dfs from there 
        for(int i=0;i<r;i++){
            dfs(i, 0, heights, pac); // 1st col
            dfs(i, c-1, heights, atl); // last col
        }

        //for every col , first row = pac , last row = atl
        for(int i=0;i<c;i++){
            dfs(0,i,heights,pac); // first row
            dfs(r-1, i, heights, atl); // last row
        }

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(pac[i][j] && atl[i][j]){
                    res.push_back({i,j});
                }
            }
        }
        return res;
    }

private:
    void dfs(int x, int y, vector<vector<int>>& heights, vector<vector<bool>>& oceans){
        oceans[x][y] = true;
        for(int i=0;i<4;i++){
            int nX = x + dir[i].first;
            int nY = y + dir[i].second;
            if(nX < 0 || nX >= heights.size() || nY < 0 || nY >= heights[0].size() || heights[nX][nY] < heights[x][y] || oceans[nX][nY]) continue;
            dfs(nX,nY,heights,oceans);
        }
    }

};
