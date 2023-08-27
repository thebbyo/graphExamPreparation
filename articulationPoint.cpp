#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
vector<int> adj[N];
int n,m, vis[N], discoveryTime[N], lowTime[N], mark[N];
int timer=1;
void dfs(int vertex, int parent =-1){
   vis[vertex] = 1;
   discoveryTime[vertex] = lowTime[vertex] = timer++;
   int child  =0;
   for(auto neighbour : adj[vertex]){
    if(neighbour == parent ) continue;
    if(!vis[neighbour]){
        dfs(neighbour, vertex);
        lowTime[vertex] = min(lowTime[vertex], lowTime[neighbour]);
        if(lowTime[neighbour] >= discoveryTime[vertex] && parent !=-1) mark[vertex] =1;
        child++;
    }
    else lowTime[vertex] = min(lowTime[vertex], discoveryTime[neighbour]);
   }
   if(child > 1 && parent == -1) mark[vertex] =1;
}
int main(){
    cin>>n>>m;
    while(m--){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0);
    for(int i = 0;i<n;i++){
        if(mark[i]) cout<<i<<endl;
    }
    return 0;
}