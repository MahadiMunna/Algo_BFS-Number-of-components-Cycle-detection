#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+5;
vector<int> adj[N];
bool visited[N];

bool dfs(int u, int p){
    bool cycle = false;
    visited[u]=true;
    for(int v:adj[u]){
        if(v==p) continue;
        if(visited[v]) return true;
        cycle = cycle | dfs(v,u);
    }
    return cycle;
}

int main(){
    int n,m;cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v;cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool cycle = false;
    for(int i=1;i<=n;i++){
        if(visited[i]) continue;
        cycle |= dfs(i,-1);
    }

    cycle?cout<<"Cycle detected":cout<<"No cycle";
    return 0;
}