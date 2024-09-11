#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void dfs(ll node, vector<ll> &vis, stack<ll> &st, vector<vector<ll>> &graph){
    
    if(vis[node]) return;
    vis[node] = 1;
    
    for(auto it: graph[node]){
        if(vis[it] == 0){
            dfs(it, vis, st, graph);
        }
    }
    st.push(node);
}

void dfs2(ll node, vector<ll> &vis2, vector<ll> &parent, ll parent_node, vector<vector<ll>> &graph) {
    vis2[node] = 1;
    parent[node] = parent_node; 
    
    for (auto it : graph[node]) {
        if (!vis2[it]) {
            dfs2(it, vis2, parent, parent_node, graph);
        }
    }
}


int main(){
    
    ll n, m;
    cin>>n>>m;
    
    vector<vector<ll>> graph(n+1);
    vector<vector<ll>> rev_graph(n+1);
    
    for(int i = 0; i<m; i++){
        
        ll u, v;
        cin>>u>>v;
        
        graph[u].push_back(v);
        rev_graph[v].push_back(u);
    }
    
    vector<ll> vis(n+1, 0);
    stack<ll> st;
    
    for(int i = 1; i<=n; i++){
        
        if(vis[i] == 0){
            dfs(i, vis, st, graph);
        }
    }
    
    vector<ll> vis2(n+1, 0);
    vector<ll> parent(n+1, -1);
    ll cnt = 0;
    while (!st.empty()) {
        ll node = st.top();
        st.pop();
        
        if (vis2[node] == 0) {
            cnt++;  
            dfs2(node, vis2, parent, cnt, rev_graph); 
        }
    }
    
    cout << cnt << endl; 
    for (int i = 1; i <= n; i++) {
        cout << parent[i] << " ";
    }
    
    return 0;
}

