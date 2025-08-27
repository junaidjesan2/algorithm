#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> adj_list[1005];
int dis[105];

void dijksta(int src)
{
    queue<pair<int, int>> q;
    q.push({src, 0});
    dis[src] = 0;

    while (!q.empty())
    {
        pair<int, int> cr_pair = q.front();
        q.pop();
        int cr_node = cr_pair.first;
        int cr_dis = cr_pair.second;

        for (auto child : adj_list[cr_node])
        {
            int child_node = child.first;
            int child_dis = child.second;
            if (cr_dis + child_dis < dis[child_node])
            {
                dis[child_node] = cr_dis + child_dis;
                q.push({child_node, dis[child_node]});
            }
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    
    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj_list[a].push_back({b, c});
        adj_list[b].push_back({a, c});
    }
    for (int i = 0; i < n; i++)
        dis[i] = INT_MAX;

    dijksta(0);

    for (int i = 0; i < n; i++)
        cout << dis[i] << " ";
    return 0;
}