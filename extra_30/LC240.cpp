class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {        // O(n+m)
        int rows = matrix.size()-1;
        int columns = matrix[0].size()-1;

        int st=0, end = columns;

        while(st<=rows && end>=0){
            if(target == matrix[st][end]){
                return true;
            }
            else if(target > matrix[st][end]){
                st++;
            }

            else if(target < matrix[st][end]){
                end--;
            }
        }
        return false;
    }
};
