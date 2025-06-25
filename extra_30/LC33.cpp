class Solution {
public:
    int search(vector<int>& nums, int target) {
        int st = 0;
        int ed = nums.size()-1;
        while(st<=ed){
            int md = st + (ed-st)/2;
            if(nums[md]==target){
                return md;
            }
            if (nums[st]<=nums[md]){     //left half sorted
                if(nums[st] <= target && target <= nums[md]){
                    ed = md-1;        // found in sorted left half
                }
                else {
                    st = md+1;  //found in right unsorted half
                }
            }
            else {                       //right half sorted
                if(nums[md]<=target && target<=nums[ed]){
                    st = md+1;    // found in sorted right half
                }
                else {
                    ed = md-1;   //found in unsorted left half
                }
            }
            
        }
        return -1;
    }
};
