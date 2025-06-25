class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        for(int i=0;i<nums.size();i++){

            if(i>0 && nums[i] == nums[i-1]){    // optimization 1
                continue;
            }
            for(int j=i+1;j<nums.size(); ){
                int k = j+1, l = nums.size()-1;

                while(k<l){
                    long long sum = (long long)nums[i] + (long long)nums[j] + (long long)nums[k] + (long long)nums[l];
                   
                   if(sum > target){
                        l--;
                    }
                    else if( sum < target ){
                            k++;
                    }
                    else{       // sum = tar
                        ans.push_back( {nums[i], nums[j], nums[k], nums[l]} );
                        k++;l--;

                        while(k<l && nums[k] == nums[k-1]){        // optimization 2
                            k++;
                        }
                    }
                }
                j++;
                while(j<nums.size() && nums[j] == nums[j-1]){       // optimization 3
                    j++;
                }
            }
        }
        return ans;
    }
};
