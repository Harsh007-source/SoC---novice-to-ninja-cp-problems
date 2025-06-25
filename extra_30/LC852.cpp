class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        
        int ed = arr.size()-2;
        int st = 1;
        while(st<=ed){
            int md = st + (ed-st)/2;
            if(arr[md]>arr[md+1] && arr[md]>arr[md-1]){
                return md;
            }
            else if(arr[md-1]<arr[md]){   //peak index on right half
                st=md+1;
            }
            else {                         //peak index on left half
                ed=md-1;
            }
        }
        return -1;
    }
};
