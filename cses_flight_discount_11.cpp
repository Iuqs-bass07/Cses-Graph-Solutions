#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF INT64_MAX
using pi = pair<int, pair<int, int>>;


void dijkstra(int n, vector<vector<pair<int, int>>> &graph){
    
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    vector<vector<int>> vis(n+1, vector<int>(2, 0));
    vector<vector<int>> dist(n+1, vector<int>(2, INF));
    
    dist[1][0] = 0;
    vis[0][0] = 0;
    pq.push({0, {1, 0}});
    
    while(!pq.empty()){
        
        int u = pq.top().second.first;
        int pos = pq.top().second.second;
        pq.pop();
        
        if(vis[u][pos]) continue;
        vis[u][pos] = 1;
        
        for(auto it: graph[u]){
            
            int v = it.first;
            int wt = it.second;
            
            if(pos == 0 && !vis[v][1] && dist[v][1] > dist[u][0] + wt / 2) {
                dist[v][1] = dist[u][0] + (wt/2);
                pq.push({dist[v][1], {v, 1}});
            }
            
            if(!vis[v][pos] && dist[v][pos] > dist[u][pos] + wt) {
                dist[v][pos] = dist[u][pos] + wt;
                pq.push({dist[v][pos], {v, pos}});
            }
        }
    }
    
    cout<<min(dist[n][0], dist[n][1])<<endl;
    return;
}


int32_t main(){
    
    int n, m;
    cin>>n>>m;
    
    vector<vector<pair<int, int>>> graph(n+1);
    for(int i = 0; i<m; i++){
        int u, v, w;
        cin>>u>>v>>w;
        graph[u].push_back({v, w});
    }
    
    dijkstra(n, graph);
    
    return 0;
}