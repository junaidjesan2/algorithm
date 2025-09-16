#include <bits/stdc++.h>
using namespace std;

class Edge
{
public:
    int a, b, c;
    Edge(int a, int b, int c)
    {
        this->a = a;
        this->b = b;
        this->c = c;
    }
};
int dis[1005];
void bellam_form(vector<Edge> edge_list, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (auto e : edge_list)
        {
            int a = e.a;
            int b = e.b;
            int c = e.c;
            if (dis[a] != INT_MAX && dis[a] + c < dis[b])
            {
                dis[b] = dis[a] + c;
            }
        }
    }
    bool cycle = false;
    for (auto e : edge_list)
    {
        int a = e.a;
        int b = e.b;
        int c = e.c;
        if (dis[a] != INT_MAX && dis[a] + c < dis[b])
        {
            cycle = true;
            break;
        }
    }
    if (cycle)
        cout << "Negative cycle detected" << endl;
    else
        cout << "No negative cycle detected" << endl;
}
int main()
{
    int n, e;
    cin >> n >> e;
    vector<Edge> edge_list;
    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edge_list.push_back(Edge(a, b, c));
    }
    for (int i = 0; i < n; i++)
    {
        dis[i] = INT_MAX;
    }
    dis[0] = 0;

    bellam_form(edge_list, n);

    for (int i = 0; i < n; i++)
    {
        cout << i << "->" << dis[i] << " ";
    }
    return 0;
}