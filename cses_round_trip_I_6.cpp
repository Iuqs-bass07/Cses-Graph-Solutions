#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll cycle_start, cycle_end;

bool dfs(ll node, ll par, vector<ll> &vis, vector<ll> &parent, vector<vector<ll>> &graph) {
    
    vis[node] = 1;
    
    for(auto it: graph[node]){
        if(it == par) continue;
        
        if(vis[it] == 1){
            cycle_end = node;
            cycle_start = it;
            return true;
        }
        parent[it] = node;
        
        if(dfs(it, node, vis, parent, graph)) return true;
        
    }
    return false;
}

int main() {
    ll n, m;
    cin >> n >> m;

    vector<vector<ll>> graph(n + 1);
    
    for (int i = 0; i < m; i++) {
        ll x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    vector<ll> vis(n + 1, 0); 
    vector<ll> parent(n + 1, -1);
    cycle_start = -1;

    for (int i = 1; i <= n; i++) {
        if (vis[i] == 0) {
            if (dfs(i, parent[i], vis, parent, graph)) break;
        }
    }

    
    if (cycle_start == -1) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        vector<int> cycle;
        cycle.push_back(cycle_start);
        for (int v = cycle_end; v != cycle_start; v = parent[v])
            cycle.push_back(v);
        cycle.push_back(cycle_start);
        reverse(cycle.begin(), cycle.end());

        cout << cycle.size()<<endl;
        for (int v : cycle)
            cout << v << " ";
        cout << endl;
    }
    
    return 0;
}
