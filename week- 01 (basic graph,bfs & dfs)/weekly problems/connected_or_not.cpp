#include <bits/stdc++.h>
using namespace std;
const int MAX = 1000;
vector<int> adj[MAX];

bool Connection_check(int start, int end)
{
    for (int neighbor : adj[start])
    {
        if (neighbor == end)
        {
            return true;
        }
    }
    return false;
}
int main()
{
    int N, E;
    cin >> N >> E;
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    int Q;
    cin >> Q;
    while (Q--)
    {
        int A, B;
        cin >> A >> B;
        if (A == B || Connection_check(A, B))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}