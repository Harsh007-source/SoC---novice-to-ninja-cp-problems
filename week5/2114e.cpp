#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
void dfs(ll node, unordered_map<ll, list<ll> >&adjList, vector<ll>& ans, ll neg, ll pos, bool curr, vector<ll>& dang, unordered_map<ll, bool>& isVisited){
    
    isVisited[node] = true;
    
    if(curr){
        pos += dang[node];
        neg -= dang[node];
    }else{
        pos -= dang[node];
        neg += dang[node];
    }

    neg = (neg > 0)*neg;
    pos = (pos > 0)*pos;
    if(curr){
        ans[node] = pos;
    }else{
        ans[node] = neg;
    }

    for(auto nbr : adjList[node]){
        if(!isVisited[nbr]){
            dfs(nbr, adjList, ans, neg, pos, !curr, dang, isVisited);
        }
    }
}
 
void solve(){
    ll n;
    cin>>n;
    vector<ll>dang(n, 0);
    for( ll i=0; i<n; i++){
        cin>>dang[i];
    }
 
    unordered_map<ll, list<ll> > adjList;
    for(ll i=1; i<n; i++){
        ll u, v;
        cin>>u>>v;
        adjList[u-1].push_back(v-1);
        adjList[v-1].push_back(u-1);
    }
    
    vector<ll>ans = dang;
    ll neg = 0, pos = 0;
    unordered_map<ll, bool> isVisited;
 
    dfs(0, adjList, ans, neg, pos, true, dang, isVisited);   
    
    for(ll i=0; i<n; i++){
        cout<<ans[i]<< " ";
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
