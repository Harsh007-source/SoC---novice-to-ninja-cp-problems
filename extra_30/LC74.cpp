class Solution {
public:


    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int sr = 0, er = matrix.size()-1;
        int col = matrix[0].size()-1;
        while(sr<=er){
            int mr = sr + (er-sr)/2;

            if(target >= matrix[mr][0] && target <= matrix[mr][col]){   // target is in this row, now apply BS in this
               int st = 0, ed = col;
                
                while(st<=ed){
                    int md = st + (ed-st)/2;
                    if(matrix[mr][md] == target){
                        return true;
                    }

                    else if(target > matrix[mr][md]){
                        st = md+1;
                    }
                    else if(target<matrix[mr][md]){
                        ed = md-1;
                    }
                }
                return false;

            }

            else if(target > matrix[mr][col]){
                sr = mr +1;
            }

            else if(target < matrix[mr][0]){
                er = mr -1;
            }

        }
        return false;
    }
};
