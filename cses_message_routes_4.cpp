#include<bits/stdc++.h>
using namespace std;

void bfs(int n, vector<vector<int>> &graph){
    
    vector<int> vis(n+1, 0);
    vector<int> par(n+1, -1);
    
    queue<int> q;
    q.push(1);
    vis[1] = 1;
    while(!q.empty()){
        
        int node = q.front();
        q.pop();
        
        for(auto it: graph[node]){
            
            if(vis[it] == 0){
                par[it] = node;
                vis[it] = 1;
                q.push(it);
            }
        }
    }
    
    if(vis[n] == 0){
        cout<<"IMPOSSIBLE"<<endl;
        return;
    }
    
    vector<int> ans;
    int idx = n;
    ans.push_back(idx);
    while(idx != 1){
        
        ans.push_back(par[idx]);
        idx = par[idx];
    }
    
    reverse(ans.begin(), ans.end());
    
    cout<<ans.size()<<endl;
    
    for(auto it: ans){
        cout<<it<<" ";
    }
    return;
}
int main(){
    
    int n, m;
    cin>>n>>m;
    
    vector<vector<int>> graph(n+1);
    for(int i = 0; i<m; i++){
        int x, y;
        cin>>x>>y;
        
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    
    bfs(n, graph);
    
    return 0;
}