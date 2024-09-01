#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, e;
    cin >> n >> e;
    vector<pair<int, int>> p;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        p.push_back({a, b});
    }
    for (int i = 0; i < p.size(); i++)
    {
        cout << p[i].first << " " << p[i].second << endl;
    }

    return 0;
}