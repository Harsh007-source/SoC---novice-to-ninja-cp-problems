#include<bits/stdc++.h>
using namespace std;
 
// logic in this probelem is that for the count of  nos. whose abs value is < target median will control the median 
//as taking target +ve than all these count nos. will come at back of target median 
//if taking target median -ve then all these count no. will come ahead of target median .
// As to make target a median we need n/2(n=even) or n/2 -1 (n=odd) nos. in left and n/2 in right so if count > n/2 then not possible to make median.
// where else nos. with abs value greater than target can come both right and left no restriction with them
 
int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        int m=arr[0];
        int count = 0;
        for(int i=1; i<n; i++){
            if(abs(m) > abs(arr[i])){
                count++;
            }
        }

        if(count > n/2){
            cout<<"NO"<<endl;
        }else{
            cout<<"YES"<<endl;
        }
    }
 
 return 0;
}
