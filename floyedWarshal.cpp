#include <bits/stdc++.h>
using namespace std;
int n,m;
const int N = 2000;
vector<vector<int>> graph (N, vector<int>(N, INT_MAX));
void floyedWarshal(int x,int y){
	for(int via=0;via<n;via++){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(graph[i][via] != INT_MAX && graph[via][j] != INT_MAX) 
					graph[i][j] = min(graph[i][j], graph[i][via] + graph[via][j]);
			}
		}
	}
	for(int i=0;i<n;i++){
		if(graph[i][i] < 0) {
			cout<<"neg cycle\n";
			return;
		}
	}
	 cout<<((graph[x][y] == INT_MAX)? -1:graph[x][y])<<" ";
			cout<<endl;
}
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++) graph[i][i] = 0;
	while(m--){
		int u,v,w;
		cin>>u>>v>>w;
		graph[u][v] = w;
	}
	int x,y;
	cin>>x>>y;
	floyedWarshal(x,y);
	return 0;
}