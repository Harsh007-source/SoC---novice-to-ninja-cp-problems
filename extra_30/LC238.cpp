class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector <int> l_pdt(n,1);
        vector <int> r_pdt(n,1);
        vector <int> answer(n);

        l_pdt[0] = 1;
        for(int i=1;i<n;i++){
            l_pdt[i] = l_pdt[i-1]*nums[i-1];
        }

        r_pdt[n-1] = 1;
        for(int i=n-2;i>=0;i--){
            r_pdt[i] = r_pdt[i+1]*nums[i+1];
        }

        for(int j=0;j<n;j++){
            answer[j] = l_pdt[j] * r_pdt[j]; 
        }
        return answer;
    }
};
