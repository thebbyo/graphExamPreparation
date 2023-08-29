#include <bits/stdc++.h>
using namespace std;
const int N = 20000000;
#define pii pair<int, int>
vector<pii> adj[N];
int n,m, vis[N];
vector<int> dist(N, INT_MAX);
bool flag = false;
void bellmanFord(int source){
	dist[source] =0;
	for(int i=0;i<n-1;i++){
		for(int j = 0;j<n;j++){
			for(auto neighbour : adj[j]){
				int neighbourVertex = neighbour.first,
				weight =  neighbour.second;
				if(dist[j] != INT_MAX && 
				   dist[j] + weight < dist[neighbourVertex]) dist[neighbourVertex] = dist[j] + weight;
			}
		}
	}
	for(int i =0;i<n;i++){
		for(auto neighbour : adj[i]){
			int neighbourVertex = neighbour.first,
			weight = neighbour.second;
			if(dist[i] != INT_MAX && dist[i] + weight < dist[neighbourVertex]){
				flag = true;
				return;
			}
		}
	}
}
int main(){
	cin>>n>>m;
	while(m--){
		int u,v,w;
		cin>>u>>v>>w;
		adj[u].push_back({v,w});
	}
	bellmanFord(0);
	if(flag) {
		cout<<"cycle\n";
		return 0;
	}
	for(int i=0;i<n;i++) cout<<i<<" "<<((dist[i] == INT_MAX)? -1:dist[i])<<endl;
	return 0;
}