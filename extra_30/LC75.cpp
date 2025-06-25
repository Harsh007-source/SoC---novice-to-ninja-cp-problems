class Solution {
public:
    void sortColors(vector<int>& arr) {
        int n = arr.size();
        int l=0,m=0,h=n-1;
        while(m<=h){

            if(arr[m]==0){
                swap(arr[l], arr[m]);
                l++;
                m++;
            }
            else if(arr[m]==1){
                m++;
            }
            else if(arr[m] ==2){
                swap(arr[m], arr[h]);
                h--;
            }
        }
    }
};
