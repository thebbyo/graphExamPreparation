#include <bits/stdc++.h>
using namespace std;
const int N = 2000, INF = 1e8;
#define pii pair<int, int>
vector<pii> adj[N];
int n,m, vis[N];
vector<int> dist(N, INT_MAX);
int ans[N][N];
priority_queue<pii, vector<pii>, greater<pii>> pq;
bool flag = false;
void bellmanFord(int source){
	dist[source] =0;
	for(int i=0;i<n;i++){
		for(int j = 0;j<=n;j++){
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
void dijkstra(int source)
{
    for(int i = 0; i<n; ++i){
        ans[source][i] = INF;
    }
    ans[source][source] = 0;
    pq.push({0, source});
    while (!pq.empty())
    {
        int wt = pq.top().first;
        int vertex = pq.top().second;
        pq.pop();
        if(ans[source][vertex]<wt) continue;
        for (auto child : adj[vertex])
        {
            int ch = child.first;
            int ch_wt = child.second;
            if (wt + ch_wt < ans[source][ch])
            {
                ans[source][ch] = wt + ch_wt;
                pq.push({ans[source][ch], ch});
            }
        }
    }
}
int main(){
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		adj[u].push_back({v,w});
	}
	for(int i=0;i<n;i++){
		adj[n].push_back({i,0});
	}
	bellmanFord(n);
	for(int i=0;i<n;i++){
		for(auto &neighbour:adj[i]) neighbour.second+=(dist[i]-dist[neighbour.first]);
	}
	for(int i=0;i<n;i++){
	 dijkstra(i);
	 for(int j=0;j<n;j++){
		ans[i][j]-=(dist[i]-dist[j]);
	}
	}
	for(int i = 0; i<n; ++i){
        for(int j = 0; j<n; ++j){
            if(i==j) continue;
            if(ans[i][j]>INF-100 )cout<<i<<" to "<<j<<": "<<"infinity"<<endl;
            else
            cout<<i<<" to "<<j<<": "<<ans[i][j]<<endl;
        }
    }
	return 0;
}