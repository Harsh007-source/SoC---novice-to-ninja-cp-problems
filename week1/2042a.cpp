#include<bits/stdc++.h>
using namespace std;
 
 
void solve(){
    int n, k;
    cin>>n>>k;
    vector<int>arr(n, 0);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    sort(arr.begin(), arr.end());
    reverse(arr.begin(), arr.end());
    int coins = 0;
    int taken=0;
    int currIdx = 0;

    for(int i=0; i<n; i++){
        taken += arr[i];
        currIdx = i;
        if(taken >= k){
            break;
        }
    }
    if(taken < k){
        cout<<k-taken<<endl;
    }
    else if(taken == k){
        cout<<0<<endl;
    }
    else{
        if(currIdx == 0){
            cout<<0<<endl;
        }else{
            cout<<k-(taken-arr[currIdx])<<endl;
        }
    }
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0); 
 
    int t ;
    cin>>t;
    for(int i=0; i<t; i++){
        solve();
    }
 
}
