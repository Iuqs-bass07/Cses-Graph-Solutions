#include<bits/stdc++.h>
using namespace std;
 
void dfs(int node, vector<vector<int>> &grid, vector<int> &vis){
    
    if(vis[node] == 1) return;
    
    vis[node] = 1;
    for(auto it: grid[node]){
        if(vis[it] == 0){
            dfs(it, grid, vis);
        }
    }
    return;
}
 
int main(){
    
    int n, m;
    cin>>n>>m;
    
    vector<vector<int>> input;
    for(int i = 0; i<m; i++){
        int x, y;
        cin>>x>>y;
        
        input.push_back({x, y});
    }
    
    vector<vector<int>> graph(n+1);
    for(auto it: input){
        graph[it[0]].push_back(it[1]);
        graph[it[1]].push_back(it[0]);
    }
    
    vector<int> vis(n+1, 0);
    int cnt = 0;
    vector<int> r;
    for(int i = 1; i<=n; i++){
        if(vis[i] == 0){
            cnt++;
            dfs(i, graph, vis);
            r.push_back(i);
        }
    }
    
    cout<<(cnt-1)<<endl;
    
    for(int i = 1; i<r.size(); i++){
        cout<<r[0]<<" "<<r[i]<<endl;
    }
    
    return 0;
