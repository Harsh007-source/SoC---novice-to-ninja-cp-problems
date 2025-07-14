class Solution {
public:

    int rec(int level, string& s, vector<int>& dp){  // no. of ways to decode from [level ... n-1]
        //pruning
        if(level == s.length()){
            return 1;
        }
        if(s[level] == '0'){
            return 0;
        }

        //base case
        if(level == s.length()-1){
            return 1;
        }

        //cache check
        if(dp[level] != -1){
            return dp[level];
        }

        //compute
        int ans=0;
        if(s[level] == '1'  ){
            ans= rec(level+1, s, dp);  // only taken itself
            ans += rec(level+2, s, dp);  // taken  next dig also
        }
        
        else if (s[level] == '2'){
            ans = rec(level +1, s, dp);

            if(s[level+1] >= '0' && s[level+1] <= '6'){
                ans += rec(level+2, s, dp);  // taken  next dig also
            }
        }
        else{
            ans = rec(level+1, s, dp);
        }

        //return
        return dp[level] = ans;
    }

    int numDecodings(string s) {
        if(s[0] =='0'){
            return 0;
        }
        vector<int> dp(s.length()+1, -1);
        return rec(0, s, dp);        
    }
};
