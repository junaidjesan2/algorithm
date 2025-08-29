#include <bits/stdc++.h>
using namespace std;
vector<int> adj_list[1005];
bool vis[1005];

void dfs(int src)
{
    vis[src] = true;
    cout << src << " ";
    for (int list : adj_list[src])
    {
        if (!vis[list])
            dfs(list);
    }
}
int main()
{
    int a, e;
    cin >> a >> e;
    while (e--)
    {
        int x, y;
        cin >> x >> y;
        adj_list[x].push_back(y);
        adj_list[y].push_back(x);
    }
    memset(vis, false, sizeof(vis));
    dfs(0);
    return 0;
}