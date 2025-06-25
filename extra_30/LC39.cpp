class Solution {
public:
    set<vector<int>> s;

    void CS(vector<int> &arr, int idx, vector<int> &comb, vector<vector<int>> &ans, int target){
        if(idx==arr.size() || target<0){   // base case
            return;
        }

        if(target == 0){  // base case
            if(s.find( {comb} ) == s.end() ){   // comb does not exist in comb
            ans.push_back( {comb} );
            }
            s.insert( {comb} );
            return;
        }

        comb.push_back( arr[idx] );  // for single and multiple inclusion

        CS(arr, idx+1, comb, ans, target - arr[idx]);   // single inclusion i+1 means next element in arr

        CS(arr, idx, comb, ans, target - arr[idx]);   // multiple inclusion with same element

        comb.pop_back();   // backtracking

        CS(arr, idx+1, comb, ans, target);
    }

    

    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        vector<int> comb;
        vector<vector<int>> ans;

        CS( arr, 0, comb, ans, target);

        return ans;
    }
};
