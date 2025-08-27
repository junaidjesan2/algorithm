#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> adj_list[n];
    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj_list[a].push_back({b, c});
        adj_list[b].push_back({a, c});
    }
    for (int i = 0; i < n; i++)
    {
        cout << i << " -> ";
        for (pair<int, int> j : adj_list[i])
        {
            cout << "(" << j.first << "," << j.second << ") ";
        }
        cout << endl;
    }
    return 0;
}