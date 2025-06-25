class Solution {
public:

    bool isPalin(string part,int st, int ed){
        while(st<=ed){
            if( part[st] != part[ed]){
                return false;
            }
            st++;ed--;
        }
        return true;
    }

    void get_all_partition(string s, vector<string> &partition, vector<vector<string>> &ans){
         if(s.size() == 0){    // base case
            ans.push_back( partition );
            return; 
        }
        for(int i=0;i<s.size() ;i++){
            
            string part = s.substr(0,i+1);
            if( isPalin( part, 0 ,part.size()-1) ){
                partition.push_back(part);
                get_all_partition(s.substr(i+1), partition, ans);

                partition.pop_back();     // backtracking
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> partition;

        get_all_partition(s, partition, ans);

        return ans;

    }
};
