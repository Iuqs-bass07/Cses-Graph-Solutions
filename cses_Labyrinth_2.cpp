#include<bits/stdc++.h>
using namespace std;

int main(){
    
    int n, m;
    cin>>n>>m;
    
    char graph[n][m], par[n][m];
    
    int vis[n][m], dist[n][m];
    memset(vis, 0, sizeof(vis));
    memset(dist, 0, sizeof(dist));
    
    int sx, sy, fx, fy;
    for(int i = 0; i<n; i++){
        
        for(int j = 0; j<m; j++){
            
            char c;
            cin>>c;
            
            graph[i][j] = c;
            
            if(c == '#'){
                vis[i][j] = 1;
            }
            
            if(c == 'A'){
                sx = i;
                sy = j;
            }
            
            if(c == 'B'){
                fx = i;
                fy = j;
            }
        }
        
    }
    //D, U, R, L
    int dr[4] = {1, -1, 0, 0};
    int dc[4] = {0, 0, 1, -1};
    
    queue<pair<int, int>> q;
    q.push({sx, sy});
    vis[sx][sy] = 1;
    
    
    while(!q.empty()){
        
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        
        for(int i = 0; i<4; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            
            if(nr >= 0 && nr < n && nc >= 0 && nc < m && vis[nr][nc] == 0){
                if(i == 0) par[nr][nc] = 'D';
                else if(i == 1) par[nr][nc] = 'U';
                else if(i == 2) par[nr][nc] = 'R';
                else par[nr][nc] = 'L';
                
                dist[nr][nc] = 1 + dist[r][c];
                vis[nr][nc] = 1;
                q.push({nr, nc});
            }
        }
    }
    
    if(vis[fx][fy] == 0){
        cout<<"NO"<<endl;
        return 0;
    }
    
    cout<<"YES"<<endl;
    cout<<dist[fx][fy]<<endl;
    
    string path;
    while(fx != sx || fy != sy){
        path += par[fx][fy];
        if(par[fx][fy] == 'U') fx++;
        else if(par[fx][fy] == 'D') fx--;
        else if(par[fx][fy] == 'L') fy++;
        else fy--;
    }
    
    reverse(path.begin(), path.end());
    cout << path << endl;
    
    return 0;
}