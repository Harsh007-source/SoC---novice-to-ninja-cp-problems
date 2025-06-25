class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int s = nums[0], f = nums[0];

        do{
            s = nums[s];         // s + 1
            f = nums[nums[f]];   //f + 2

        }while(s != f);

        s = nums[0];
    
        while( s != f){
            s = nums[s];
            f = nums[f];
        }

        return s;
    }

};
