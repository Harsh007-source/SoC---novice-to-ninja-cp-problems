class Solution {
public:

    bool tour(vector<vector<int>> grid, int r, int col, int expValue, int n){
        if(expValue == n*n){
            return true;
        }
        if(r<0 || col<0 || r>=n || col>=n || grid[r][col] != expValue){ // base case
            return false;
        }
        // 8 possible moves
        bool ans1 = tour(grid, r-2, col+1, expValue+1,n);
        bool ans2 = tour(grid, r-1, col+2, expValue+1,n);
        bool ans3 = tour(grid, r+1, col+2, expValue+1,n);
        bool ans4 = tour(grid, r+2, col+1, expValue+1,n);
        bool ans5 = tour(grid, r+2, col-1, expValue+1,n);
        bool ans6 = tour(grid, r+1, col-2, expValue+1,n);
        bool ans7 = tour(grid, r-1, col-2, expValue+1,n);
        bool ans8 = tour(grid, r-2, col-1, expValue+1,n);

        return ans1 || ans2 || ans3 || ans4 || ans5 || ans6 || ans7 || ans8;
        
    }

    bool checkValidGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        return tour(grid, 0, 0, 0,n);
    }
};
