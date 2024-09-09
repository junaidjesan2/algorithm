#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adj[N];
bool vis[N];
bool p[N];
bool ans;

void dfs(int parent)
{
    vis[parent] = true;
    p[parent] = true;
    for (int child : adj[parent])
    {
        if (p[child])
        {
            ans = true;
        }

        if (!vis[child])
        {
            dfs(child);
        }
    }
    p[parent] = false;
}

int main()
{
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        // adj[b].push_back(a);
    }
    memset(vis, false, sizeof(vis));
    memset(p, -1, sizeof(p));
    ans = false;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            dfs(i);
        }
    }
    if (ans)
        cout << "Cycle Found";
    else
        cout << "Cycle is not Found";

    return 0;
}