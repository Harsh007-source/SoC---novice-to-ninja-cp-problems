#include<bits/stdc++.h>
using namespace std;
 
 
void solve(){
    int n;
    cin>>n;
    vector<int>arr(n+1, 0);
    for(int i=1; i<=n; i++){
        cin>>arr[i];
    }

    vector<int>grp(n+1, -1);
    int k=1;  // grp 1
    for(int i=1; i<=n; i++){
        if(grp[i] != -1){
            continue;
        }
        grp[i] = k;
        int j = arr[i];
        while(j != i){
            grp[j] = k;
            j=arr[j];
        }
        k++;
    }

    vector<bool>chk(k+1, 0);
    vector<int>sz(k+1, 0);
    for(int i=1; i<=n; i++){
        sz[grp[i]]++;
    }

    int ans = 0;
    for(int i=0; i<n; i++){
        int d;
        cin>>d;
        if(!chk[grp[d]]){
            ans += sz[grp[d]];
            chk[grp[d]] = 1;
        }
        cout<<ans<<" ";
    }
    cout<<endl;

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
