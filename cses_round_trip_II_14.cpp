#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll cycle_start, cycle_end;

bool dfs(ll node, vector<ll> &col, vector<ll> &parent, vector<vector<ll>> &graph) {
    col[node] = 1;  
    
    for (auto it : graph[node]) {
        if (col[it] == 0) {  
            parent[it] = node;
            if (dfs(it, col, parent, graph)) return true;
        } else if (col[it] == 1) {
            cycle_start = it;
            cycle_end = node;
            return true;
        }
    }
    
    col[node] = 2;
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
    }

    vector<ll> col(n + 1, 0); 
    vector<ll> parent(n + 1, -1);
    cycle_start = -1;

    for (int i = 1; i <= n; i++) {
        if (col[i] == 0) {
            if (dfs(i, col, parent, graph)) break;
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
