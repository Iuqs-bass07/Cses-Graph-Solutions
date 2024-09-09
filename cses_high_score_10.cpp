#include<bits/stdc++.h>
using namespace std;
#define int long long


const int INF = 1e18;
 
void dfs(vector<vector<int>>&g, vector<int>&s, int u) {
  s[u] = 1;
  for(auto v:g[u])
    if (!s[v])
      dfs(g, s, v);
}


int32_t main(){
    
    int n, m, u, v, w;cin>>n>>m;
    vector<vector<int>>a(n+1);
    vector<vector<int>>b(n+1);
    vector<vector<int>>e(m);
    for(int i = 0; i<m; i++){
        cin>>u>>v>>w;
        a[u].push_back(v);
        b[v].push_back(u);
        e[i]={u, v, -1*w};
    }
    vector<int>vis(n+1), vis1(n+1);
    dfs(a, vis, 1);
      dfs(b, vis1, n);
      vector<int>d(n+1, INF);
      d[1]=0;
      bool flag=0;
      for (int i=1; i<=n;i++) {
        flag=0;
        for (auto it:e){
            //   tie(u, v, w) = x;
              int u = it[0];
              int v = it[1];
              int w = it[2];
              if(vis[u] and vis1[v] and d[u]+w<d[v]){
                  flag=1;
                  d[v]=d[u]+w;
              }
        }
      }
      if(flag)cout<<-1;
      else cout<<d[n]*-1;
    
    return 0;
}    