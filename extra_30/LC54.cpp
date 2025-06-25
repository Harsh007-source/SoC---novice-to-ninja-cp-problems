class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int col = matrix[0].size()-1, row = matrix.size()-1;
        int st_row = 0, ed_row = row, st_col = 0, ed_col = col;
        vector<int> ans;

        while(st_row <= ed_row && st_col <= ed_col){
            // top
            for(int j = st_col ; j<=ed_col ;j++){
                ans.push_back( matrix[st_row][j] ) ;
            }

            // right
            for(int i = st_row + 1 ; i<=ed_row; i++){
                ans.push_back(matrix[i][ed_col]);
            }

            // bottom
            for(int j = ed_col -1; j>=st_col; j--){
                if(st_row == ed_row){
                    break;
                }
                ans.push_back(matrix[ed_row][j]);
            }

            // left
            for(int i = ed_row -1; i>st_row; i--){
                if(st_col == ed_col){
                    break;
                }
                ans.push_back( matrix[i][st_col] );
            }

            st_row++; ed_row--;
            st_col++; ed_col--;
        }
        return ans;
    }
};
