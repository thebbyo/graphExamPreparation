#include <bits/stdc++.h>
using namespace std;
const int N = 200000;
int n, m, vis[N], sum =0;
#define pii pair<int,int>
vector<pair<int,pii>>adj;
int size[N], parent[N];
void make(int v){
	parent[v] = v;
	size[v] = 1;
}
int find(int v){
	if(parent[v] == v) return v;
	return parent[v] = find(parent[v]);
}
void Union(int a, int b){
	a = find(a);
	b = find(b);
	if(a!=b){
		if(size[a] < size[b]) swap(a,b);
		parent[b] = a;
		size[a] += size[b];
	}
}
int main(){
	cin>>n>>m;
	while(m--){
		int u,v,w;
		cin>>u>>v>>w;
		adj.push_back({w,{u,v}});
		adj.push_back({w,{v,u}});
	}
	int mst = 0;
	sort(adj.begin(), adj.end());
	for(int i=0;i<n;i++) make(i);
		for(auto adj:adj){
			int w = adj.first,
			u = adj.second.first,
			v = adj.second.second;
			if(find(u) == find(v)) continue;
			Union(u,v);
			mst+=w;
			cout<<u<<' '<<v<<' '<<w<<endl;
		}
		cout<<mst<<endl;
	return 0;
}
