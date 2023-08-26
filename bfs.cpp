#include <bits/stdc++.h>
using namespace std;
const int N = 200000;
vector<int> adj[N];
int n, m;
int vis[N];
queue<int> qq;
vector<int> dist(N, INT_MAX);
void bfs(int vertex, int parent = 0){
	dist[vertex] =0;
	qq.push(vertex);
	vis[vertex] = true;
	while(!qq.empty()){
		int current = qq.front();
		qq.pop();
		for(auto neighbour:adj[current]){
			if(!vis[neighbour]){
				dist[neighbour] = min(dist[neighbour], dist[current]+1);
				qq.push(neighbour);
				vis[neighbour] = true;
			}
		}
	}
}
int main(){
	cin>>n>>m;
	while(m--){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(v);
	}
	bfs(0);
	for(int i=0;i<n;i++){
		cout<<i<<" ";
		if(dist[i] != INT_MAX) cout<<dist[i]<<endl;
		else cout<<"impossible\n";
	}
	cout<<endl;
	return 0;
}
