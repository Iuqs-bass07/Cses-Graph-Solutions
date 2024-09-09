#include<bits/stdc++.h>
using namespace std;


int bfs(int node, vector<char> &col, vector<vector<int>> &graph){
    
    queue<pair<int, char>> q;
    q.push({node, 'w'});
    col[node] = 'w';
    
    while(!q.empty()){
        
        int node = q.front().first;
        char ch = q.front().second;
        q.pop();
        
        for(auto it: graph[node]){
            
            if(col[it] == ch){
                return -1;
            }
            
            if(col[it] == 'n'){
                if(ch == 'w'){
                    col[it]= 'b';
                    q.push({it, 'b'});
                }
                else{
                    col[it] = 'w';
                    q.push({it, 'w'});
                }
            }
        }
    }
    return 1;
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
    
    vector <char> col(n+1, 'n');
    
    for(int i = 1; i<=n; i++){
        if(col[i] == 'n'){
            int x = bfs(i, col, graph);
            
            if(x == -1){
                cout<<"IMPOSSIBLE";
                return 0;
            }
        }
    }
    
    for(int i = 1; i<=n; i++){
        if(col[i] == 'w'){
            cout<<1<<" ";
        }
        else cout<<2<<" ";
    }
    return 0;
}