#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> adj_list[1005];
int dis[105];

void dijksta(int src)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});
    dis[src] = 0;

    while (!pq.empty())
    {
        pair<int, int> cr_pair = pq.top();
        pq.pop();
        int cr_node = cr_pair.second;
        int cr_dis = cr_pair.first;

        for (auto child : adj_list[cr_node])
        {
            int child_node = child.first;
            int child_dis = child.second;
            if (cr_dis + child_dis < dis[child_node])
            {
                dis[child_node] = cr_dis + child_dis;
                pq.push({dis[child_node], child_node});
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