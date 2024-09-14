#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void dfs(ll node, vector<ll> &vis, unordered_map<ll, vector<ll>> &graph){
    
    if(vis[node]) return;
    vis[node] = 1;
    
    for(auto it: graph[node]){
        if(!vis[it]){
            dfs(it, vis, graph);
        }
    }
}

bool isPossible(ll n, vector<ll> &indegree, vector<ll> &outdegree, unordered_map<ll, vector<ll>> &graph){
    
    bool flag = true;
    if(outdegree[1] - indegree[1] != 1) return false;
    if(outdegree[n] - indegree[n] != -1) return false;
    for(ll i = 2; i<n; i++){
        if(indegree[i] != outdegree[i]) return false;
    }
    vector<ll> vis(n+1, 0);
    dfs(1, vis, graph);
    
    for(ll i = 1; i<=n; i++){
        if(vis[i] == 0 && (indegree[i] != 0 || outdegree[i] != 0)) return false;
    }
    
    return true;
}

vector<ll> Euler_path(unordered_map<ll, vector<ll>> &mp){
    
    stack<ll> st;
    st.push(1);
    
    vector<ll> path;
    while(!st.empty()){
        
        ll node = st.top();
        
        if(mp[node].size() != 0){
            ll nxt_node = mp[node].back();
            mp[node].pop_back();
            
            st.push(nxt_node);
        }
        else{
            st.pop();
            path.push_back(node);
        }
    }
    reverse(path.begin(), path.end());
    return path;
}
int main(){
    
    ll n, m;
    cin>>n>>m;
    
    unordered_map<ll, vector<ll>> graph;
    vector<ll> indegree(n+1, 0);
    vector<ll> outdegree(n+1, 0);
    for(ll i = 0; i<m; i++){
        ll u, v;
        cin>>u>>v;
        
        outdegree[u]++;
        indegree[v]++;
        graph[u].push_back(v);
    }
    
    bool possible = isPossible(n, indegree, outdegree, graph);
    if(possible == false){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    vector<ll> path = Euler_path(graph);
    
    for(auto it: path){
        cout<<it<<" ";
    }
    
    return 0;
}