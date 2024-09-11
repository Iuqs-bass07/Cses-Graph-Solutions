#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void dfs(ll node, vector<ll> &vis, stack<ll> &st, vector<vector<ll>> &graph){
    
    if(vis[node]) return;
    vis[node] = 1;
    
    for(auto it: graph[node]){
        if(!vis[it]) dfs(it, vis, st, graph);
    }
    
    st.push(node);
}

void dfs2(ll node, vector<ll> &vis, vector<vector<ll>> &graph){
    
    if(vis[node]) return;
    vis[node] = 1;
    
    for(auto it: graph[node]){
        if(!vis[it]) dfs2(it, vis, graph);
    }
    return;
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
        if(!vis[i]){
            dfs(i, vis, st, graph);
        }
    }
    
    
    vector<ll> vis2(n+1, 0);
    ll node = st.top();
    st.pop();
    dfs2(node, vis2, rev_graph);
    
    for(int i =1; i<=n; i++){
        if(vis2[i] == 0){
            cout<<"NO"<<endl;
            cout<<i<<" "<<node<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
    return 0;
}