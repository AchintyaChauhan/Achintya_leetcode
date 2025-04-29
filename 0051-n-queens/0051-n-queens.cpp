class Solution {
public:
    bool issafe(int row, int col, int n, vector<string>& board) {
        // Check column
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q') return false;
        }

        // Check upper-left diagonal
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') return false;
        }

        // Check upper-right diagonal
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q') return false;
        }

        return true;
    }

    void solve(int i, int n, vector<string>& board, vector<vector<string>>& ans) {
        if (i == n) {
            ans.push_back(board);
            return;
        }
        for (int j = 0; j < n; j++) {
            if (issafe(i, j, n, board)) {
                board[i][j] = 'Q';
                solve(i + 1, n, board, ans);
                board[i][j] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));  
        solve(0, n, board, ans);
        return ans;
    }
};
