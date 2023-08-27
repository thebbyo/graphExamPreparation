#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
vector<int> adj[N], adjT[N];
int n,m, vis[N];
stack<int> st;
void dfs(int vertex){
    vis[vertex] = 1;
    for(auto neighbour:adj[vertex]){
        if(!vis[neighbour]) dfs(neighbour);
    }
    st.push(vertex);
}
void dfsT(int vertex){
    cout<<vertex<<" ";
    vis[vertex] = 1;
    for(auto neighbour: adjT[vertex]){
        if(!vis[neighbour]) dfsT(neighbour);
    }
}
int main(){
    cin>>n>>m;
    while(m--){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adjT[v].push_back(u);
    }
    for(int i=0;i<n;i++){
        if(!vis[i]) dfs(i);
    }
    memset(vis, false, sizeof(vis));
    int scc=0;
    while(!st.empty()){
        int top = st.top();
        st.pop();
        if(!vis[top]){
            scc++;
            dfsT(top);
            cout<<endl;
        }
    }
    return 0;
}