class Solution {
public:

    void print_subset(vector<int> nums, vector<int>& ans, int i, vector<vector<int>> &all_subset){  // make changes in ans vector , all_subset
        if( i== nums.size() ){         // base case
            all_subset.push_back( {ans} );
            return;
        }

        ans.push_back(nums[i]);                      // inclusion
        print_subset(nums, ans, i+1, all_subset);

        ans.pop_back();                                // backtracking

        int idx = i+1;                                            // exclusion
        while( idx < nums.size() && nums[i] == nums[idx]){
            idx++;
        }

        print_subset(nums, ans, idx, all_subset);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> ans;
        vector<vector<int>> all_subset;
        print_subset(nums, ans, 0, all_subset);
        return all_subset;

    }
};
