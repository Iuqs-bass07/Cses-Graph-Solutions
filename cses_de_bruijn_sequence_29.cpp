#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void dfs(string prefix, string &res, unordered_set<string> &visit) {
        for(int i = 0; i < 2; i++) {
            string temp = prefix + to_string(i);
            if(visit.find(temp) != visit.end()) continue;
            visit.insert(temp);
            dfs(temp.substr(1, prefix.size()), res, visit);
            res += to_string(i);
        }
    }

int main(){
    
    int n;
    cin>>n;
    
    // if(n == 1){
    //      cout<< "10";
    //      return 0;
    // }
    unordered_set<string> visit;
    string res, prefix(n-1, '0');
    dfs(prefix, res, visit);
    res += prefix;
    
    cout<<res;
    return 0;
}


