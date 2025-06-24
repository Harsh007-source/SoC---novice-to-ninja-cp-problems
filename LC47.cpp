class Solution {
public:

    void get_perms( vector<int> &nums, vector<vector<int>> &ans, int idx, set<vector<int>> &s){

        if(idx == nums.size() ){              // base case
            if(s.find(nums) == s.end()){  // not found means nums is unique
                ans.push_back( nums );
                s.insert(nums);
            }
            return;
        }

        for( int i=idx; i<nums.size(); i++){
            swap(nums[i], nums[idx] );
            get_perms( nums, ans, idx+1, s);

            swap(nums[i], nums[idx] );              // backtracking 
        }

}
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        set<vector<int>> s;  // to store all permutatations before pushing back in ans soo as to check uniqueness
        get_perms( nums, ans, 0, s);

        return ans;
    }
};
