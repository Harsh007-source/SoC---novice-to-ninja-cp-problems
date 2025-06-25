class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int piv = -1;
        for(int i = nums.size()-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                piv = i;
                break;
            }
        }
        if(piv==-1){            // given array has max value in all permutation so next value is minimun or starting
            reverse(nums.begin(), nums.end());
            return;
        }

        for(int i= nums.size()-1; i> piv;i--){           // finding next larger element than pivot
            if(nums[i]>nums[piv]){
                swap(nums[i], nums[piv]);
                break; 
            }
        }

        int i=piv+1, j=nums.size()-1;   // reversing array from piv+1 to n-1
        while(i<=j){
            swap(nums[i], nums[j]);
            i++;j--;
        }
    }
};
