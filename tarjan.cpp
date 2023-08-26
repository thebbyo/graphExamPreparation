#include <bits/stdc++.h>
using namespace std;
const int N = 200000;
vector<int> adj[N];
#define pii pair<int,int>
int n, m;
int vis[N], discoveryTime[N], lowTime[N];
vector<pii> bridges;
int timer = 1;
int numOfBridge =0;
void dfs(int vertex, int parent = -1){
	vis[vertex] = true;
	discoveryTime[vertex] = lowTime[vertex] = timer++;
	for(auto neighbour : adj[vertex]){
		if(neighbour == parent) continue;
		if(!vis[neighbour]){
			dfs(neighbour, vertex);
			lowTime[vertex] = min(lowTime[vertex], lowTime[neighbour]);
			if(lowTime[neighbour] > discoveryTime[vertex]){
				numOfBridge++;
				cout<<vertex<<" "<<neighbour<<endl;
			}
		}
		else{
			lowTime[vertex] = min(lowTime[vertex], discoveryTime[neighbour]);
		}
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
