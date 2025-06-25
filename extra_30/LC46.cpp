class Solution {
public:

    void get_perms(vector<int> &nums, vector<vector<int>> &ans, int idx){
        if(idx == nums.size()){                // base case
            ans.push_back( {nums} );
            return;
        }

        for(int i=idx; i<nums.size(); i++){
            swap(nums[i], nums[idx]);

            get_perms(nums, ans, idx+1);

            swap(nums[i], nums[idx]);          // backtracking
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        
        get_perms(nums, ans, 0);
        return ans;
    }
};
