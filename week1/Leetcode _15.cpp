class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end() );

        for(int i=0;i<nums.size();i++){
            if( i>0 && nums[i] == nums[i-1]){   // optimization if there are two repeatative elements for i 
                continue;
            }
            int j = i+1;
            int k = nums.size()-1;

            while(j<k){
                if(nums[j] + nums[k] > -nums[i]){
                    k--;
                }
                else if(nums[j] + nums[k] < -nums[i]){
                    j++;
                }
                else{
                    ans.push_back(  { nums[i], nums[j], nums[k] } );
                    j++;k--;
                    while( j<k && nums[j] == nums[j-1]){   // optimization if we got one ans then after j++ we will get again same j
                        j++;
                    }
                }
            }
        }
        return ans;
    }
};
