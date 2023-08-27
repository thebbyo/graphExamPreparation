#include <bits/stdc++.h>
using namespace std;
const int N = 200000;

int n, m, vis[N], sum =0;
#define pii pair<int,int>
priority_queue<pii, vector<pii>, greater<pii>> pq;
vector<pii> adj[N];
void mst(){
	pq.push({0,0});
	while(!pq.empty()){
		auto top = pq.top();
		pq.pop();
		int weight = top.first, node = top.second;
		if(vis[node]) continue;
		vis[node] = 1;
		sum+=weight;
		for(auto neighbour : adj[node]){
			if(!vis[neighbour.first]) pq.push({neighbour.second, neighbour.first});
		}
	}
}
int main(){
	cin>>n>>m;
	while(m--){
		int u,v,w;
		cin>>u>>v>>w;
		adj[u].push_back({v,w});
		adj[v].push_back({u,w});
	}
	mst();
	cout<<sum<<endl;
	return 0;
}
