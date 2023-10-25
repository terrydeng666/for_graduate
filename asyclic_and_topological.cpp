#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int t;//拓墣順序
bool cycle;
void dfs(vector<vector<int> > &adj,vector<int> &visited,vector<int> &topo,int v)
{
    if(visited[v]==1) // gray-> back edge
    {
        cycle=true;
        return ;
    }
    if(visited[v]==2) return;
    visited[v]=1;
    for(int i=1;i<=topo.size();i++)
    {
        if(adj[v][i]) dfs(adj,visited,topo,i);
    }
    visited[v]=2;
    topo[t++]=v;
}
void solve()
{
    int n;
    cout << "enter n :";
    cin >> n;
    vector<int> visited(n+1,0);//0:white 1:gray 2:black
    int m;
    cout << "enter m:";
    cin >> m;
    vector<vector<int> > adj(n+1,vector<int>(n+1,0));
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin >> u >> v;
        adj[u][v]=1;
    }
    vector<int> topo_order(n,0);
    t=0;
    cycle=false;
    for(int i=1;i<=n;i++)
    {
        if(!visited[i]) dfs(adj,visited,topo_order,i);
    }
    if(cycle) 
    {
        cout << "cycle\n";
        return;
    }
    for(int i=topo_order.size()-1;i>=0;i--)
    {
        cout << topo_order[i] << " ";
    }
    return;
}

int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    solve();
    return 0;
}