#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<ll, ll>;

int main(){
    
    ll n, m;
    cin>>n>>m;
    
    vector<vector<ll>> edges;
    for(int i = 0; i<m; i++){
        ll x, y, wt;
        cin>>x>>y>>wt;
        
        edges.push_back({x, y, wt});
    }
    
    vector<ll> dist(n+1, 1e18);
    vector<ll> par(n+1, -1);
    ll start = -1;
    vector<int> ans;
    dist[1] = 0;
    for(int i = 1; i<=n; i++){
        
        start = -1;
        for(auto it: edges){
            
            ll u = it[0], v = it[1], wt = it[2];
            if(dist[u] + wt < dist[v]){
                dist[v] = dist[u] + wt;
                par[v] = u;
                start = v;
            }
        }
    }
    
    if(start == -1){
        cout<<"NO"<<endl;
    }
    else{
        ll y = start;
        
        for (int i = 0; i < n; ++i){
            y = par[y];
        }
            
        vector<int> path;
        for (int cur = y;; cur = par[cur]) {
            path.push_back(cur);
            if (cur == y && path.size() > 1)
                break;
        }
        reverse(path.begin(), path.end());

        cout << "YES"<<endl;
        for (int u : path){
            cout << u << ' ';
        }
    } 
    
    return 0;
}    