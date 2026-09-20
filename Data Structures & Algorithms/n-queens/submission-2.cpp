class Solution {
public:
    vector<string> board;
    vector<bool> col, posDiag, negDiag;
    vector<vector<string>> res;
    // pos diagonal r-c are equal 0,0 1,1 2,2 ... it can become for ex 0,4 -> 0-4 = -4 hence add +n -4+4 = 0
    // neg diagonal r+c are equal 0,4 1,3 2,2 3,1 
    vector<vector<string>> solveNQueens(int n) {
        col.resize(n, false);
        posDiag.resize(2 * n, false); // total diagonals are 2*n -1
        negDiag.resize(2 * n, false);
        board.resize(n, string(n, '.'));

        backtrack(0, n);
        return res;
    }

    void backtrack(int r, int n) {
        if (r == n) {
            res.push_back(board);
            return;
        }
        for (int c = 0; c < n; c++) {
            if (col[c] || posDiag[r + c] || negDiag[r - c + n]) {
                continue;
            }
            col[c] = true;
            posDiag[r + c] = true;
            negDiag[r - c + n] = true;
            board[r][c] = 'Q';

            backtrack(r + 1, n);

            col[c] = false;
            posDiag[r + c] = false;
            negDiag[r - c + n] = false;
            board[r][c] = '.';
        }
    }
};