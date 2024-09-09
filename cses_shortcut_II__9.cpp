#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<ll, ll>;

int main(){
    
    
    ll n, m, q;
    cin>>n>>m>>q;
    
    vector<vector<ll>> dist(n+1, vector<ll>(n+1, 1e18));
    for(int i = 0; i<m; i++){
        
        ll a, b, c;
        cin>>a>>b>>c;
        
        if(c < dist[a][b]){
            dist[a][b] = c;
            dist[b][a] = c;
        }
    }
    for(int i = 1; i<=n; i++){
        dist[i][i] = 0;
    }
    
    
    //floyd warshall algo;
    for(int via = 1; via<= n; via++){
        for(int i = 1; i<= n; i++){
            
            for (int j = i + 1; j <= n; j++) {
				long long new_dist = dist[i][via] + dist[via][j];
				if (new_dist < dist[i][j]) {
					dist[i][j]  = new_dist;
					dist[j][i] = dist[i][j];
				}
			}
        }
    }
    
    for(int i = 0; i<q; i++){
        
        ll x, y;
        cin>>x>>y;
        
        if(x == y) dist[x][y] = 0;
        if(dist[x][y] >= 1e18){
            dist[x][y] = -1;
        }
        
        cout<<dist[x][y]<<endl;
    }
    return 0;
}
