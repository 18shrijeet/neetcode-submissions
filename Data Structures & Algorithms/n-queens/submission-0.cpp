class Solution {
public:
    
    bool isSafe(int r, int c, vector<int>& col, vector<int>& diag, vector<int>& rdiag, int n)
    {
        if(col[c] || diag[r-c+n-1] || rdiag[r+c]) return false;
        return true;
    }
    void solve(int row, int n, vector<string>& cur, vector<int>& col, vector<int>& diag, vector<int>& rdiag, vector<vector<string>>& res){
        if(row == n){
            res.push_back(cur);
            return;
        }
        for(int j=0;j<n;j++){
            if(isSafe(row,j,col, diag, rdiag, n)){
                cur[row][j] = 'Q';
                col[j]=1;
                diag[row-j+n-1]=1;
                rdiag[row+j]=1;

                solve(row+1,n,cur, col, diag, rdiag, res);

                cur[row][j] = '.';
                col[j]=0;
                diag[row-j+n-1]=0;
                rdiag[row+j]=0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string>cur(n, string(n, '.'));
        vector<int> col(n,0);
        vector<int> diag(n*2,0);
        vector<int> rdiag(n*2, 0);

        solve(0, n, cur, col, diag, rdiag, res);
        return res;
    }
};
