class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int st=0, ed=n-1;
        if(n ==1) return nums[0];

        while(st<=ed){
            int md = st + (ed-st)/2;

            if(md==0 && nums[md] != nums[md+1]) return nums[md];
            if(md == n-1 && nums[md] != nums[md-1]) return nums[md];
            
            if(nums[md-1] != nums[md] && nums[md] != nums[md+1]){
                return nums[md];
            }

            if(md%2 == 0){          //right and left halfs have even entries 
                if(nums[md-1] == nums[md]) {   //single value on left half
                    ed = md-1;
                }
                else st = md+1;           //single value on right half
            }

            else{                   //right and left halfs have odd entries
                if(nums[md-1] == nums[md]){   //single value on right half
                    st = md+1;
                }
                else{
                    ed = md-1;              //single value on left half
                }
            }
        }
        return -1;
    }
};
