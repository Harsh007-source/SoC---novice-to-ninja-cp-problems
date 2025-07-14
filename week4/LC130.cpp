class Solution {
public:
    void dfs(int i, int j, int m, int n, vector<vector<char>>& board, vector<vector<bool>>& isVisited) {
        // Check if indices are out of bounds or cell is not 'O' or already visited
        if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != 'O' || isVisited[i][j]) {
            return;
        }

        // Mark the current cell as visited
        isVisited[i][j] = true;

        // Explore all four directions
        dfs(i, j + 1, m, n, board, isVisited); // right
        dfs(i, j - 1, m, n, board, isVisited); // left
        dfs(i - 1, j, m, n, board, isVisited); // up
        dfs(i + 1, j, m, n, board, isVisited); // down
    }

    void solve(vector<vector<char>>& board) {
        // Handle empty board case
        if (board.empty() || board[0].empty()) {
            return;
        }

        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> isVisited(m, vector<bool>(n, false));

        // Check first and last row
        for (int j = 0; j < n; j++) {
            if (board[0][j] == 'O' && !isVisited[0][j]) {
                dfs(0, j, m, n, board, isVisited);
            }
            if (board[m - 1][j] == 'O' && !isVisited[m - 1][j]) {
                dfs(m - 1, j, m, n, board, isVisited);
            }
        }

        // Check first and last column
        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O' && !isVisited[i][0]) {
                dfs(i, 0, m, n, board, isVisited);
            }
            if (board[i][n - 1] == 'O' && !isVisited[i][n - 1]) {
                dfs(i, n - 1, m, n, board, isVisited);
            }
        }

        // Flip unvisited 'O' cells to 'X'
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O' && !isVisited[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
