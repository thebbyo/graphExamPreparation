#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
vector<int> adj[N], adjT[N];
int n,m, vis[N], discoveryTime[N], lowTime[N];
int timer =1, numberOfBridges =0;
void dfs(int vertex, int parent =-1){
    vis[vertex] =1;
    discoveryTime[vertex] = lowTime[vertex] = timer++;
    for(auto neighbour : adj[vertex]){
        if(neighbour == parent) continue;
        if(!vis[neighbour]){
            dfs(neighbour, vertex);
            lowTime[vertex] = min(lowTime[vertex], lowTime[neighbour]);
            if(lowTime[neighbour] > discoveryTime[vertex]){
                numberOfBridges++;
                cout<<vertex<<" "<<neighbour<<endl;
            }
        }
        else lowTime[vertex] = min(lowTime[vertex], lowTime[neighbour]);
    }
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
    return 0;
}