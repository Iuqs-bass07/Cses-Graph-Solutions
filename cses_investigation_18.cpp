#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<ll, ll>;
int mod = 1e9+7;

void djikstra(int n, vector<vector<pi>> &graph){
    
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    pq.push({0, 1});
    
    vector<ll> dist(n+1, 1e18);
    vector<ll> ways(n+1, 0);
    vector<int> max_nodes(n+1, 0);
    vector<int> min_nodes(n+1, 1e18);
    
    dist[1] = 0;
    ways[1] = 1;
    max_nodes[1] = 0;
    min_nodes[1] = 0;
    
    while(!pq.empty()){
        ll wt = pq.top().first;
        ll node = pq.top().second;
        pq.pop();
        
        if (wt > dist[node]) continue;
        
        for(auto it: graph[node]){
            ll next_node = it.first;
            ll next_dist = it.second;
            
            if(dist[node] + next_dist < dist[next_node]){
                dist[next_node] = next_dist + dist[node];
                ways[next_node] = ways[node] % mod;  // New shortest path found
                pq.push({dist[next_node], next_node});
                
                max_nodes[next_node] = max_nodes[node] + 1;
                min_nodes[next_node] = min_nodes[node] + 1;
            }
            else if(dist[node] + next_dist == dist[next_node]){
                ways[next_node] = (ways[next_node] + ways[node]) % mod;  // Multiple shortest paths
                
                max_nodes[next_node] = max(max_nodes[next_node], max_nodes[node] + 1);
                min_nodes[next_node] = min(min_nodes[next_node], min_nodes[node] + 1);
            }
        }
    }
    
    cout<<dist[n]<<" "<<ways[n]<<" "<<min_nodes[n]<<" "<<max_nodes[n]<<endl;
    return;
}


int main(){
    
    ll n, m;
    cin>>n>>m;
    
    vector<vector<pi>> graph(n+1);
    for(int i = 0; i<m; i++){
        ll x, y, wt;
        cin>>x>>y>>wt;
        
        graph[x].push_back({y, wt});
    }
    
    djikstra(n, graph);
    
    
    return 0;
}