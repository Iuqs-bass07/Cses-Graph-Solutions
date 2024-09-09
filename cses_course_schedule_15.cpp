#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    
    ll n, m;
    cin>>n>>m;
    
    vector<vector<ll>> graph(n+1);
    vector<ll> indeg(n+1, 0);
    
    for(int i = 0; i<m; i++){
        
        ll x, y;
        cin>>x>>y;
        graph[x].push_back(y);
        
        indeg[y]++;
    }
    
    queue<ll> q;
    vector<ll> ans;
    for(ll i = 1; i<=n; i++){
        if(indeg[i] == 0){
            q.push(i);
        }
    }
    
    while(!q.empty()){
        
        ll node = q.front();
        q.pop();
        ans.push_back(node);
        
        for(auto it: graph[node]){
            indeg[it]--;
            
            if(indeg[it] == 0){
                q.push(it);
            }
        }
    }
    
    if(ans.size() != n){
        cout<<"IMPOSSIBLE"<<endl;
    }
    else{
        for(auto it: ans){
            cout<<it<<" ";
        }
    }
    return 0;
}