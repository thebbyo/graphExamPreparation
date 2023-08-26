#include <bits/stdc++.h>
using namespace std;
const int N = 200000;
vector<int> adj[N];
int n, m;
int vis[N];
bool flag = false;
void dfs(int vertex, int parent = -1){
	vis[vertex] = true;
	for(auto neighbour:adj[vertex]){
		if(!vis[neighbour]) dfs(neighbour, vertex);
		else{
			if(parent != neighbour){
				flag = true;
				return;
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
		adj[v].push_back(u);

	}
	for(int i=0;i<n;i++){
		if(!vis[i]) dfs(i);
	}
	cout<<((flag)? "true":"false")<<endl;
	return 0;
}
