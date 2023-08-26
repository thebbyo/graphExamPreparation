#include <bits/stdc++.h>
using namespace std;
const int N = 200000;
vector<int> adj[N];
int n, m;
int vis[N];
stack<int> st;
void topologicalSort(int vertex){
	vis[vertex] = true;
	for(auto neighbour:adj[vertex]){
		if(!vis[neighbour]) topologicalSort(neighbour);
	}
	st.push(vertex);
}
int main(){
	cin>>n>>m;
	while(m--){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
	}
	for(int i=0;i<n;i++){
		if(!vis[i]) topologicalSort(i);
	}
	while(!st.empty()){
		cout<<st.top()<<" ";
		st.pop();
	}
	cout<<endl;
	return 0;
}
