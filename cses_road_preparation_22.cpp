#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<ll, ll>;
//wt, node, parent
int mod = 1e9+7;

int main(){
    
    ll n, m;
    cin>>n>>m;
    
    vector<vector<pi>> graph(n+1);
    for(int i = 0; i<m; i++){
        ll x, y, wt;
        cin>>x>>y>>wt;
        
        graph[x].push_back({y, wt});
        graph[y].push_back({x, wt});
    }
    
    vector<ll> vis(n+1, 0);
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    pq.push({0, 1});
    ll cost = 0;
    
    while(!pq.empty()){
        
        ll wt = pq.top().first;
        ll node = pq.top().second;
        pq.pop();
        
        if(vis[node] == 1) continue;
        
        vis[node] = 1;
        cost += wt;
        
        for(auto it: graph[node]){
            if(vis[it.first] == 0){
                pq.push({it.second, it.first});
            }
        }
    }
    
    bool flag = true;
    for(int i = 1; i<=n; i++){
        if(vis[i] == 0)flag= false;
    }
    
    
    if(flag == false) cout<<"IMPOSSIBLE"<<endl;
    else cout<<cost<<endl;
    
    return 0;
}