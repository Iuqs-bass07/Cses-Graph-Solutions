#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<ll, ll>;
int mod = 1e9+7;

class Disjoint_Set{

public:

    vector<ll> parent;
    vector<ll> sz;
    
    Disjoint_Set(ll n){
        parent.resize(n+1, -1);
        sz.resize(n+1, 1);
        
        for(int i = 1; i<=n; i++){
            parent[i] = i;
        }
    }
    
    ll find_Parent(ll node){
        
        if(node == parent[node]) return node;
        return parent[node] = find_Parent(parent[node]);
    }
    
    void Union_size(ll u, ll v){
        
        ll par_u = find_Parent(u);
        ll par_v = find_Parent(v);
        
        if(par_u == par_v) return;
        if(sz[par_v] > sz[par_u]){
            sz[par_v] += sz[par_u];
            parent[par_u] = par_v;
        }
        else{
            sz[par_u] += sz[par_v];
            parent[par_v] = par_u;
        }
        return;
    }
    
};
int main(){
    
    ll n, m;
    cin>>n>>m;
    
    Disjoint_Set ds(n);
    ll max_size = 1;
    ll comp = n;
    for(int i = 1; i<=m; i++){
        
        ll u, v;
        cin>>u>>v;
        
        ll par_u = ds.find_Parent(u);
        ll par_v = ds.find_Parent(v);
        
        if(par_u == par_v){
            cout<<comp<<" "<<max_size<<endl;
        }
        else{
            
            ds.Union_size(u, v);
            max_size = max({max_size, ds.sz[par_v], ds.sz[par_u]});
            comp -= 1;
            cout<<(comp)<<" "<<max_size<<endl;
        }
    }
    return 0;
}