#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int mod = 1e9+7;
void dfs(ll node, stack<ll> &st, vector<ll> &vis, vector<vector<ll>> &graph){
    
    vis[node] = 1;
    for(auto it: graph[node]){
        
        if(!vis[it]){
            dfs(it, st, vis, graph);
        }
    }
    st.push(node);
}

int main(){
    
    ll n, m;
    cin>>n>>m;
    
    vector<vector<ll>> graph(n+1);
    vector<ll> vis(n+1, 0);
    stack<ll> st;
    
    for(int i = 0; i<m; i++){
        
        ll x, y;
        cin>>x>>y;
        graph[x].push_back(y);
        
    }
    
    for(ll i = 1; i<=n; i++){
        if(vis[i] == 0){
            dfs(i, st, vis, graph);
        }
    }
    
    vector<ll> dist(n+1, INT_MIN);
    dist[1] = 1;
    
    while(!st.empty()){
        
        int node = st.top();
        st.pop();
        
        
        if(dist[node] != INT_MIN){
            for(auto it: graph[node]){
                if(dist[it] == INT_MIN){
                    dist[it] = dist[node];
                }
                else{
                    dist[it] = (dist[it] + dist[node])%mod;
                }
            }
        }
    }
    
    if(dist[n] == INT_MIN) dist[n] = 0;
    cout<<((dist[n])%mod)<<endl;
    
    return 0;
}