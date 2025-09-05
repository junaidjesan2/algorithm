#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

class Edge
{
public:
    int u, v;
    long long w;

    Edge(int uu, int vv, long long ww) : u(uu), v(vv), w(ww) {}
    Edge(){};
};

int main()
{
    int N, E;
    cin >> N >> E;

    vector<Edge> edges(E);
    for (int i = 0; i < E; ++i)
    {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        edges[i] = Edge(u, v, w);
    }

    int S;
    cin >> S;

    vector<long long> dist(N + 1, INF);
    dist[S] = 0;

    for (int i = 0; i < N - 1; ++i)
    {
        bool updated = false;
        for (auto &e : edges)
        {
            if (dist[e.u] != INF && dist[e.u] + e.w < dist[e.v])
            {
                dist[e.v] = dist[e.u] + e.w;
                updated = true;
            }
        }
        if (!updated)
            break;
    }

    bool negative_cycle = false;
    for (auto &e : edges)
    {
        if (dist[e.u] != INF && dist[e.u] + e.w < dist[e.v])
        {
            negative_cycle = true;
            break;
        }
    }

    if (negative_cycle)
    {
        cout << "Negative Cycle Detected" << endl;
        return 0;
    }

    int T;
    cin >> T;
    while (T--)
    {
        int D;
        cin >> D;
        if (dist[D] == INF)
        {
            cout << "Not Possible" << endl;
        }
        else
        {
            cout << dist[D] << endl;
        }
    }

    return 0;
}
