class Solution {
public:

    void get_subset(vector<int> &nums, vector<int>& ans, int i, vector<vector<int>>& subsets){
        if(i == nums.size() ){
            subsets.push_back( {ans} );
            return;
        }

        ans.push_back( nums[i] );             // inclusion
        get_subset(nums, ans, i+1, subsets);

        ans.pop_back();  // backtracking removed the element which was push backed

        get_subset(nums, ans, i+1, subsets);   // exclusion
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> ans;
        vector<vector<int>> subsets;
        get_subset(nums, ans, 0, subsets);
        return subsets;

    }
};
