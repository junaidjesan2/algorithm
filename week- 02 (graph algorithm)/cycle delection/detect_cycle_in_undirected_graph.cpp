#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adj[N];
bool vis[N];
bool cycleFound;
int parentArray[N];

void bfs(int s)
{
    vector<int> q;
    vis[s] = true;
    while (!q.empty())
    {
        int parent = q.front();
        cout << parent << endl;
        q.pop_back();
        for (int child : adj[parent])
        {
            if (vis[child] == true && parentArray[parent] != child)
            {
                cycleFound = true;
            }

            if (!vis[child])
            {
                vis[child] = true;
                q.push_back(child);
            }
        }
    }
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
        adj[b].push_back(a);
    }
    memset(vis, false, sizeof(vis));
    memset(parentArray, -1, sizeof(parentArray));
    cycleFound = false;
    for (int i = 0; i < N; i++)
    {
        if (!vis[i])
        {
            bfs(i);
        }
    }

    if (cycleFound == true)
    {
        cout << "Cycle Found" << endl;
    }
    else if (cycleFound == false)
    {
        cout << "Cycle is not Found" << endl;
    }

    return 0;
}