#include <bits/stdc++.h>
using namespace std;
const int N = 105;
const long long INF = 1e16;
long long dist[N][N];
int main()
{
    int n, E;
    cin >> n >> E;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            dist[i][j] = INF;
        }
        dist[i][i] = 0;
    }
    for (int i = 0; i < E; i++)
    {
        int A, B;
        long long W;
        cin >> A >> B >> W;
        dist[A][B] = min(dist[A][B], W);
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    int Q;
    cin >> Q;
    while (Q--)
    {
        int X, Y;
        cin >> X >> Y;
        if (dist[X][Y] == INF)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << dist[X][Y] << endl;
        }
    }
    return 0;
}