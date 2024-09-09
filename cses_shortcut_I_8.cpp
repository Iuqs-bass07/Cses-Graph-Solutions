#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<ll, ll>;

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<pi>> graph(n + 1);
    vector<ll> dist(n + 1, LLONG_MAX);
    vector<bool> vis(n + 1, false);
    
    for(int i = 0; i < m; i++) {
        ll x, y, wt;
        cin >> x >> y >> wt;
        graph[x].push_back({y, wt});
    }

    priority_queue<pi, vector<pi>, greater<pi>> pq;
    pq.push({0, 1});
    dist[1] = 0;

    while(!pq.empty()) {
        ll wt = pq.top().first;
        ll node = pq.top().second;
        pq.pop();
        
        if (vis[node]) continue;
        vis[node]=1;
        
        for(auto it : graph[node]) {
            ll next_node = it.first;
            ll edge_weight = it.second;
            
            if(wt + edge_weight < dist[next_node]) {
                dist[next_node] = wt + edge_weight;
                pq.push({dist[next_node], next_node});
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        cout << dist[i] << " "; 
    }

    return 0;
}
