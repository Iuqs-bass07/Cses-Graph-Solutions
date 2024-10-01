// #include<bits/stdc++.h>
// using namespace std;

// class BinaryLifting {
// public:
//     vector<vector<int>> dp, graph;
//     vector<int>  depth;
//     int maxLevel = 0;
//     int timer = 0;
    
//     BinaryLifting(int n, vector<int> &parent) {
//         int m = ceil(log2(n));
//         maxLevel = 30;
//         depth.resize(n+1, 0);
//         dp.resize(maxLevel, vector<int>(n + 1, -1));
//         timer = 0;
//     }
    
//     void build(int n, vector<int> &parent) {
        
        
//         for (int i = 1; i <= n; i++) {
//             dp[0][i] = parent[i];
//         }
        
//         for (int j = 1; j < maxLevel; j++) {
//             for (int node = 1; node <= n; node++) {
//                 if (dp[j-1][node] != -1) {
//                     dp[j][node] = dp[j-1][dp[j-1][node]];
//                 }
//             }
//         }
//     }
    
//     void dfs(int node, int par, int l, vector<vector<int>> &graph){
        
//         depth[node] = l;
        
//         for(auto ch: graph[node]){
//             if(ch != par){
//                 dfs(ch, node, l+1, graph);
//             }
//         }
        
//     }
//     int kthParent(int node, int k) {
//         for (int i = 0; i < maxLevel; i++) {
//             if (k & (1 << i)) {
//                 node = dp[i][node];
//                 if (node == -1) break;
//             }
//         }
//         return node;
//     }
    
    
    
//     int lca(int u, int v) {
        
//         if (depth[u] > depth[v]) swap(u, v);
    
        
//         int diff = depth[v] - depth[u];
//         for (int i = 0; i < maxLevel; i++) {
//             if (diff & (1 << i)) {
//                 v = dp[i][v];  
//             }
//         }
    
//         if (u == v) return u;
    
//         for (int i = maxLevel - 1; i >= 0; i--) {
//             if (dp[i][u] != dp[i][v]) {
//                 u = dp[i][u]; 
//                 v = dp[i][v];  
//             }
//         }
    
//         return dp[0][u];
//     }
    
// };

// int main(){
    
//     int n, q;
//     cin>>n>>q;
    
//     vector<int> parent(n+1, -1);
    
//     for(int i = 1; i<=n; i++){
//         cin>>parent[i];
//     }
    
//     BinaryLifting tree(n, parent);
//     tree.build(n, parent);
//     while(q--){
//         int node, k;
//         cin>>node>>k;
        
        
//         cout << tree.kthParent(node, k) << endl;
//     }
//     return 0;
// }

#include <bits/stdc++.h>

using namespace std;
const int maxN = 2e5+1;
const int logK = 31;

int N, Q, x, k, p[maxN][logK];

int main(){
    scanf("%d %d", &N, &Q);
    for(int i = 1; i <= N; i++)
        scanf("%d", &p[i][0]);
    for(int j = 1; j < logK; j++)
        for(int i = 1; i <= N; i++)
            p[i][j] = p[p[i][j-1]][j-1];

    for(int q = 0; q < Q; q++){
        scanf("%d %d", &x, &k);
        for(int i = 0; i < logK; i++)
            if(k&(1<<i))
                x = p[x][i];
        printf("%d\n", x);
    }
}