#include<bits/stdc++.h>
using namespace std;
 
void bfs(int r, int c, vector<vector<int>> &vis, vector<vector<char>> &grid){
    
    int n = grid.size();
    int m = grid[0].size();
    
    queue<pair<int, int>> q;
    q.push({r, c});
    
    while(!q.empty()){
        
        int nr = q.front().first;
        int nc = q.front().second;
        q.pop();
        vis[nr][nc] = 1;
        
        if(nr+1 < n && vis[nr+1][nc] == 0 && grid[nr+1][nc] == '.'){
            q.push({nr+1, nc});
        }
        
        if(nr -1 >= 0 && vis[nr-1][nc] == 0 && grid[nr-1][nc] == '.'){
            q.push({nr-1, nc});
        }
        
        if(nc+1 < m && vis[nr][nc+1] == 0 && grid[nr][nc+1] == '.'){
            q.push({nr, nc+1});
        }
        
        if(nc-1 >= 0 && vis[nr][nc-1] == 0 && grid[nr][nc-1] == '.'){
            q.push({nr, nc-1});
        }
        
    }
    
    return;
}
 
void dfs(int r, int c, vector<vector<char>> &grid, vector<vector<int>> &vis){
    
    int n = grid.size();
    int m = grid[0].size();
    
    if(r < 0 || r >= n || c < 0 || c >= m || vis[r][c] == 1 || grid[r][c] == '#'){
        return;
    }
    
    vis[r][c] = 1;
    dfs(r+1, c, grid, vis);
    dfs(r-1, c, grid, vis);
    dfs(r, c+1, grid, vis);
    dfs(r, c-1, grid, vis);
    
    return;
}
 
int main(){
    
    int n, m;
    cin>>n>>m;
    
    vector<vector<char>> grid;
    for(int i = 0; i<n; i++){
        
        vector<char> temp;
        for(int i = 0; i<m; i++){
            char ch;
            cin>>ch;
            temp.push_back(ch);
        }
        grid.push_back(temp);
    }
    
    vector<vector<int>> vis(n, vector<int>(m, 0));
    int cnt = 0;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            
            if(vis[i][j] == 0 && grid[i][j] == '.'){
                dfs(i, j,  grid, vis);
                cnt++;
            }
        }
    }
    
    cout<<cnt;
    return 0;
}