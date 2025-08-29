#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[105];
bool vis[105];
bool path_vis[105];
bool cycle;

void dfs(int src)
{
    vis[src] = true;
    path_vis[src] = true;
    for (int child : adj_list[src])
    {
        if (vis[child] && path_vis[src])
            cycle = true;
        if (!vis[child])
        {
            dfs(child);
        }
    }
    path_vis[src] = false;
}

int main()
{
    int n, m;
    cin >> n >> m;
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
    }
    memset(vis, false, sizeof(vis));
    memset(path_vis, false, sizeof(path_vis));
    cycle = false;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])    
        {
            dfs(i);
        }
    }
    if (cycle)
        cout << "Cycle Found" << endl;
    else
        cout << "No Cycle" << endl;
    return 0;
}