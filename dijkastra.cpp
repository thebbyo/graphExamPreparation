#include <bits/stdc++.h>
using namespace std;
const int N = 200000;
#define pii pair<int,int>
vector<vector<pii>>adj(N);
vector<int> dist (N, INT_MAX);
int vis[N],n,m;
priority_queue<pii, vector<pii>, greater<pii>> pq;
void dijkastra(int source){
    dist[source] = 0;
    pq.push({0, source});
    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        if(vis[u]) continue;
        vis[u] = 1;
        for(auto neighbour:adj[u]){
            int neighbourVertex = neighbour.first;
            int weight = neighbour.second;

            if(!vis[neighbourVertex] && dist[u] != INT_MAX && dist[u] + weight < dist[neighbourVertex]){
                dist[neighbourVertex] = dist[u] + weight;
                pq.push({dist[neighbourVertex], neighbourVertex});
            }
        }
    }
}
int main(){
    //int n,m;
    cin>>n>>m;
    while(m--)
    {
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
    }
    dijkastra(0);
    for(int i =0;i<n;i++){
        cout<<i<<" "<<dist[i]<<endl;
    }
    return 0;
}