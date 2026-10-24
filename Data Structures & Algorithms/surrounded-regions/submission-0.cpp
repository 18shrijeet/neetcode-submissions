class Solution {
public:
    void dfs(vector<vector<char>>& board, int i, int j, vector<vector<bool>>& visited){
        if(i < 0 || j< 0 || i >= board.size() || j >= board[0].size() || visited[i][j] || board[i][j] == 'X') return;
        board[i][j] = '*';
        visited[i][j] = true;
        dfs(board,i+1,j,visited);
        dfs(board,i-1,j,visited);
        dfs(board,i,j+1,visited);
        dfs(board,i,j-1,visited);
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        vector<vector<bool>>visited(m,vector<bool>(n,false));
        for(int j=0;j<n;j++){
            // first row
            if(board[0][j] == 'O')dfs(board,0,j, visited);
        }
        for(int j=0;j<n;j++){
            // last row
            if(board[m-1][j] == 'O')dfs(board,m-1,j, visited);
        }
        for(int j=0;j<m;j++){
            // first column
            if(board[j][0] == 'O')dfs(board,j,0, visited);
        }
        for(int j=0;j<m;j++){
            // last column
            if(board[j][n-1] == 'O')dfs(board,j,n-1,visited);
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j] != '*') board[i][j] = 'X';
                else board[i][j] = 'O';
            }
        }

    }
};
