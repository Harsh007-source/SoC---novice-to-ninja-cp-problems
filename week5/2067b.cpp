#include<bits/stdc++.h>
using namespace std;
 
 
void solve(){
    int n;
    cin>>n;
    map<int, int> freq;  // (ele, freq)
    set<int> s;   // stores in ascending order
    vector<int>arr(n+1, 0);
    for(int i=1; i<=n; i++){
        int val; cin>>val;
        s.insert(val);
        freq[val]++;
    } 
    
    while(!s.empty()){
        int min = *s.begin();
        if(freq[min] == 1){
            cout<<"NO\n";
            return;
        }
            freq[min+1] += freq[min] -2;  // remove the match pair
            freq[min] = 0;
            s.erase(min);

            if(freq[min+1]){
                s.insert(min+1);
            }
        
    }
    cout<<"YES\n";
 
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0); 
 
    int t;
    cin>>t;
    for(int i=0; i<t; i++){
        solve();
    }
}
