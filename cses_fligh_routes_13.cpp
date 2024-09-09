#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<ll, ll>;

void kth_djikstra(int n, int m, int k, vector<vector<pair<ll, ll>>> &graph){
    
    vector<ll> count(n+1, 0);
    
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    pq.push({0, 1});
    
    vector<ll> result;
    while(!pq.empty() && count[n] < k){
        
        ll wt = pq.top().first;
        ll node = pq.top().second;
        pq.pop();
        
        count[node]++;
        if(node == n){
            
            result.push_back(wt);
            continue;
        }
        
        
        if(count[node] <= k){
            
            for(auto it: graph[node]){
                pq.push({wt + it.second, it.first});
            }
        }
    }
    
    for(auto it: result){
        cout<<it<<" ";
    }
    return;
    
}

int main(){
    
    int n, m, k;
    cin>>n>>m>>k;
    
    vector<vector<pi>>graph(n+1);
    for(int i = 0; i<m; i++){
        ll u, v, wt;
        cin>>u>>v>>wt;
        
        graph[u].push_back({v, wt});
    }
    
    kth_djikstra(n, m, k, graph);
    return 0;
}







