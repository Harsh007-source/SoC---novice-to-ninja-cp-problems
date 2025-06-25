class Solution {
public:

    bool isSafe( vector<string> board, int row, int col, int n){            // O(n)
        for(int j=0; j<n;j++){
            if(board[row][j] == 'Q'){         //  vertical check, same row, different column
                return false;
            }
        }

        for(int i=0; i<n;i++){
            if(board[i][col] == 'Q'){          // horizontal check, different rows, same column
                return false;
            }
        }

        for(int i = row, j = col; i>=0 && j>=0 ; i--, j--) {                // left diagonal 1 up
            if( board[i][j] == 'Q'){                                            // as we are filling queens rows wise from 0 to n therefore we check previous reows only
                return false;
            }
            
        }

        for( int i = row, j = col; i>=0 && j<n ; i--, j++){               // right  diagonal 2 up
            if(board[i][j] == 'Q'){
                return false;
            }
        }


        return true;
    }

    void nQueens( vector<string> &board, int row, int n, vector<vector<string>> &ans ){
        
        if(row == n){                              // base case
            ans.push_back( {board} );
            return;
        }

        for(int j=0; j<n;j++){                  // ith queen in ith row each row has one string and each string has n elements
            if( isSafe( board, row, j, n )){      // j = column
                board[row][j] = 'Q';
                nQueens( board, row+1, n, ans);
                board[row][j] = '.';       // backtracking removing Q before moving to next column of same row

            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));    // n strings each strings contains n elements, one string represents one row
        vector<vector<string>> ans;

        nQueens( board, 0, n, ans);
        return ans;
    }
};
