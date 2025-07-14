#include<bits/stdc++.h>
using namespace std;
using ll = long long;
 
 
void solve(){
    ll n;
    cin>>n;
    vector<ll>arr(n+1, 0);
    for(ll i=1; i<=n; i++){
        cin>>arr[i];
    }
    vector<ll>ans(n+1, 0);
    vector<ll>prefixMax(n+1, 0);  // max ele from 1 ... i
    ll maxi = INT_MIN;
    for(ll i=1; i<=n; i++){
        maxi = max(maxi, arr[i]);
        prefixMax[i] = maxi;
    }

    ll sum = 0;
    for(ll k=1 ; k<=n; k++){
        if(k==1){
            ans[k] = prefixMax[n];
        }else{
            sum += arr[n-k+2];
            ans[k] = sum + prefixMax[n-k+1];
        }
    }

    for(ll i=1; i<=n; i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0); 
 
    ll t;
    cin>>t;
    for(ll i=0; i<t; i++){
        solve();
    }
 
}
