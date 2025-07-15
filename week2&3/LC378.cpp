class Solution {
public:

    int count(int md, vector<vector<int>>& matrix){
        int cnt=0;
        for(int i=0; i<matrix.size(); i++){
            int curr = upper_bound(matrix[i].begin(), matrix[i].end(), md) - matrix[i].begin();
            cnt += curr;
        }
        return cnt;
    }

    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int st = matrix[0][0];
        int ed = matrix[n-1][n-1];
        while(st < ed){
            int md = st + (ed-st)/2;
            int cnt = count(md, matrix);
            if(cnt >= k){
                ed = md;
            }else{
                st = md+1;
            }
        }
        return st;
    }
};
