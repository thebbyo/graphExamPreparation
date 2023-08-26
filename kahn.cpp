#include <bits/stdc++.h>
using namespace std;
const int N = 200000;
vector<int> adj[N];
int n, m;
int vis[N], inDegree[N];
queue<int> qq;
void kahn(){
	for(int i=0;i<n;i++){
		if(!inDegree[i]) qq.push(i);
	}
	while(!qq.empty()){
		int top = qq.front();
		qq.pop();
		cout<<top<<" ";
		for(auto neighbour:adj[top]){
			inDegree[neighbour]--;
			if(!inDegree[neighbour]) qq.push(neighbour);
		}
	}
}
int main(){
	cin>>n>>m;
	while(m--){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		inDegree[v]++;
	}
	//for(int i=0;i<n;i++) cout<<i<<" :"<<inDegree[i]<<endl;
	kahn();
	cout<<endl;
	return 0;
}
