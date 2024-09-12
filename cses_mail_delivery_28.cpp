#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void dfs(ll node, vector<ll> &vis, vector<vector<ll>> &graph) {
    stack<ll> s;
    s.push(node);
    vis[node] = 1;

    while (!s.empty()) {
        ll curr = s.top();
        s.pop();

        for (auto it: graph[curr]) {
            if (!vis[it]) {
                vis[it] = 1;
                s.push(it);
            }
        }
    }
}

bool isPossible(ll n, vector<vector<ll>> &graph) {
    vector<ll> degree(n+1, 0);

    // Calculate the degree of each node
    for (ll i = 1; i <= n; i++) {
        degree[i] = graph[i].size();
    }

    // Check for even degree and connectivity
    vector<ll> vis(n+1, 0);
    dfs(1, vis, graph);

    for (int i = 1; i <= n; i++) {
        if (degree[i] % 2 == 1) return false;  // Odd degree
        if (degree[i] != 0 && vis[i] == 0) return false;  // Disconnected component
    }
    return true;
}

vector<ll> Euler_circuit(ll n, vector<unordered_map<ll, ll>> &matrix) {
    stack<ll> curr;
    vector<ll> circuit;
    curr.push(1);

    while (!curr.empty()) {
        ll node = curr.top();
        
        if (!matrix[node].empty()) {
            // Pick any adjacent edge
            auto it = matrix[node].begin();
            ll neighbor = it->first;
            curr.push(neighbor);
            matrix[node][neighbor]--;
            if (matrix[node][neighbor] == 0) matrix[node].erase(neighbor);
            matrix[neighbor][node]--;
            if (matrix[neighbor][node] == 0) matrix[neighbor].erase(node);
        } else {
            circuit.push_back(node);
            curr.pop();
        }
    }

    return circuit;
}


int main() {
    ll n, m;
    cin >> n >> m;

    vector<vector<ll>> graph(n+1);
    vector<ll> degree(n+1);

    // Using an adjacency map for space optimization
    vector<unordered_map<ll, ll>> matrix(n+1);

    for (int i = 0; i < m; i++) {
        ll x, y;
        cin >> x >> y;

        graph[x].push_back(y);
        graph[y].push_back(x);
        matrix[x][y]++;
        matrix[y][x]++;
    }

    // Check if an Eulerian circuit is possible
    bool check = isPossible(n, graph);
    if (!check) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    // Find the Eulerian circuit
    vector<ll> ans = Euler_circuit(n, matrix);
    for (auto it: ans) {
        cout << it << " ";
    }

    return 0;
}
