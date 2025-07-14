#include<bits/stdc++.h>
using namespace std;
using ll = long long ;
 
 
void solve() {
    ll n;
    cin >> n;
    vector<ll> arr(n), posSum(n), negSum(n);

    ll pos = 0, neg = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (arr[i] > 0) pos += arr[i];
        else neg -= arr[i];
        posSum[i] = pos;
        negSum[i] = neg;
    }

    ll ans = max(pos, neg);

    for (int i = 0; i < n; i++) {
        ll a = posSum[i];
        ll b = (i < n - 1) ? (negSum[n - 1] - negSum[i]) : 0;
        ans = max(ans, a + b);
    }

    cout << ans << '\n';
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
