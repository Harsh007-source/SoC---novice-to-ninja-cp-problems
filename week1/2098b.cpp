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

    vector<int>buyH;
    for(int i=0; i<n; i++){
        if(abs(i - (n-i-1)) <= k+1){
            buyH.push_back(arr[i]);
        }
    }
    cout<<buyH[buyH.size()-1] - buyH[0] +1<<endl;
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
