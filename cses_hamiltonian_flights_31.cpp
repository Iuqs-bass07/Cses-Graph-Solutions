#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;

// ll solve(ll pos, ll mask, ll n, const vector<vector<ll>>& graph, vector<vector<ll>>& dp) {
//     if (mask == (1 << n) - 1) return 1; 
    
//     if (dp[pos][mask] != -1) return dp[pos][mask];
    
//     ll ans = 0;
//     for (ll i = 0; i < n; ++i) {
//         if (!(mask & (1 << i)) && graph[pos][i]) {
//             ans = (ans + solve(i, mask | (1 << i), n, graph, dp)) % mod;
//         }
//     }
    
//     return dp[pos][mask] = ans;
// }

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> G(N);  
    vector<vector<ll>> dp(N, vector<ll>(1 << N, 0)); 
    vector<vector<bool>> inqueue(N, vector<bool>(1 << N, false)); 
    queue<pair<int, int>> Q;  // BFS queue

    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        G[a - 1].push_back(b - 1);
    }

    dp[0][1] = 1; 
    Q.push({0, 1});
    inqueue[0][1] = true;

    while (!Q.empty()) {
        int u = Q.front().first;
        int mask = Q.front().second;
        Q.pop();

        if (u != N - 1) {
            for (int v : G[u]) {
                int newMask = mask | (1 << v);
                if ((mask & (1 << v)) == 0) { 
                    dp[v][newMask] = (dp[v][newMask] + dp[u][mask]) % MOD;
                    if (!inqueue[v][newMask]) {
                        Q.push({v, newMask});
                        inqueue[v][newMask] = true;
                    }
                }
            }
        }
    }

    cout << dp[N - 1][(1 << N) - 1] << endl;

    return 0;
}