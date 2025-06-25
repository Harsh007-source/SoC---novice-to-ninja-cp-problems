class Solution {
public:

    bool isSafe( vector<vector<char>>& board, int row, int col, char dig){
        // check horizontal, row same col different
        for( int i =0; i<=8; i++){
            if(board[row][i] == dig){
                return false;
            }
        }

        // check for vertical, row different col same
        for( int i = 0;i<=8; i++){
            if(board[i][col] == dig){
                return false;
            }
        }

        // check in subgrid
        int sr = (row/3)*3;
        int sc = (col/3)*3;

        for(int i=sr; i<=sr+2; i++){
            for(int j=sc; j<=sc+2; j++){
                if( board[i][j] == dig){
                return false;
                }
            }
        }

        return true;
    }

    bool SS(vector<vector<char>>& board, int row, int col){
        
        int nextR = row;
        int nextC = col+1;
        if(col == 9){
            nextR = row +1;
            nextC = 0;
        }

        if(row == 9){       // base case
            return true;
        }

        if(board[row][col] != '.'){ // cell is not empty
           
            return SS(board, nextR, nextC);
        }
            // placing dig from 1 to 9 and check
        for(char dig = '1'; dig<='9'; dig++){

            if( isSafe(board, row, col, dig) ){
                board[row][col] = dig;
                
                 if( SS(board, nextR, nextC) ){  // aage se true aaya to hum bhi true return karenge
                    return true;
                }
                board[row][col] = '.';
            }
        }
        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        
        if( SS(board, 0,0) ){
            return;
        }
        
    
    }
};
