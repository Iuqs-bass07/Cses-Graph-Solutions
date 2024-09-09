#include<bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
 
int main(){
    
    int n, m;
    cin >> n >> m;
    
    queue<pi> q1;
    queue<pi> q2;
    vector<vector<char>> graph(n, vector<char>(m));
    vector<vector<int>> dist1(n, vector<int>(m, INT_MAX));
    vector<vector<int>> dist2(n, vector<int>(m, INT_MAX));
    
    queue<pi> q;
    pi start;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            
            char ch;
            cin >> ch;
            graph[i][j] = ch;
            
            if(ch == 'A'){
                q1.push({i, j});
                dist1[i][j] = 0;
                q.push({i, j});
                start = {i, j}; 
            }
            
            if(ch == 'M'){
                q2.push({i, j});
                dist2[i][j] = 0;
            }
        }
    }
    
    // Directions: R, L, D, U
    int dr[4] = {0, 0, -1, 1};
    int dc[4] = {1, -1, 0, 0};
    char move[4] = {'R', 'L', 'U', 'D'};
    
    // BFS for player 'A'
    while(!q1.empty()){
        int r = q1.front().first;
        int c = q1.front().second;
        q1.pop();
        
        for(int i = 0; i < 4; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            
            if(nr >= 0 && nr < n && nc >= 0 && nc < m && dist1[nr][nc] == INT_MAX && graph[nr][nc] != '#'){
                dist1[nr][nc] = 1 + dist1[r][c];
                q1.push({nr, nc});
            }
        }
    }
    
    // BFS for monsters 'M'
    while(!q2.empty()){
        int z = q2.size();
        for(int x = 0; x < z; x++){
            int r = q2.front().first;
            int c = q2.front().second;
            q2.pop();
            
            for(int i = 0; i < 4; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                
                if(nr >= 0 && nr < n && nc >= 0 && nc < m && dist2[nr][nc] == INT_MAX && graph[nr][nc] != '#'){
                    dist2[nr][nc] = 1 + dist2[r][c];
                    q2.push({nr, nc});
                }
            }
        }
    }
    
    vector<vector<int>> valid(n, vector<int>(m, 0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(graph[i][j] == '#' || dist2[i][j] <= dist1[i][j]){
                valid[i][j] = -1; 
            }
        }
    }
    
    int sx = start.first;
    int sy = start.second;
    
    vector<vector<int>> vis(n, vector<int>(m, 0));
    vector<vector<char>> path_dir(n, vector<char>(m));
    vector<vector<pi>> parent(n, vector<pi>(m, {-1, -1}));
    vis[sx][sy] = 1;
    int fx = -1, fy = -1;
    
    while(!q.empty()){
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        
        // Check if we reached an exit
        if(r == 0 || r == n-1 || c == 0 || c == m-1){
            cout << "YES" << endl;
            fx = r, fy = c;
            break;
        }
        
        // Explore all four directions
        for(int i = 0; i < 4; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            
            if(nr >= 0 && nr < n && nc >= 0 && nc < m && valid[nr][nc] != -1 && vis[nr][nc] == 0){
                vis[nr][nc] = 1;
                q.push({nr, nc});
                parent[nr][nc] = {r, c};  // Store parent cell
                path_dir[nr][nc] = move[i];  // Store direction moved
            }
        }
    }
    
    // If an exit was found
    if(fx != -1 && fy != -1){
        string path = "";
        pi current = {fx, fy};
        
        // Reconstruct the path by backtracking from the exit
        while(current != make_pair(sx, sy)){
            char dir = path_dir[current.first][current.second];
            path += dir;
            current = parent[current.first][current.second]; // Move to the parent cell
        }
        
        reverse(path.begin(), path.end()); // Reverse the path to get it in the correct order
        cout << path.size() << endl;  // Print the path length
        cout << path << endl;  // Print the path
    } 
    else {
        cout << "NO" << endl; // No path found
    }
 
    return 0;
}