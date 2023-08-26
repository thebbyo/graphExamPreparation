#include <bits/stdc++.h>
using namespace std;
const int N = 200000;
vector<int> adj[N];
int n, m;
int vis[N], recurStack[N];
bool flag = false;
void dfs(int vertex){
	recurStack[vertex] = true;
	vis[vertex] = true;
	for(auto neighbour:adj[vertex]){
		if(!vis[neighbour]) dfs(neighbour);
		else{
			if(recurStack[neighbour]){
				flag = true;
				return;
			}
		}
	}
	recurStack[vertex] = false;
}
int main(){
	cin>>n>>m;
	while(m--){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		//adj[v].push_back(u);

	}
	for(int i=0;i<n;i++){
		if(!vis[i]) dfs(i);
	}
	cout<<((flag)? "true":"false")<<endl;
	return 0;
}
