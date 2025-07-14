class Solution {
public:

    int rec(int sum, int n, vector<int>& dp){  //min no. of ways to sum with square nos. make up to (n-sum)
        //pruning
        if(sum>n){
            return 1e9;
        }

        //base case
        if(sum == n){
            return 0;
        }

        //cache check
        if(dp[sum] != -1){
            return dp[sum];
        }

        //compute
        int ans = INT_MAX;
        for(int i=1; i*i <=n; i++){
            int res = 1+ rec(sum + i*i, n, dp);
            ans = min(ans, res);
        } 

        //return
        return dp[sum] = ans;
    }

    int numSquares(int n) {
        vector<int> dp(n, -1);
        return rec(0, n, dp);
    }
};
