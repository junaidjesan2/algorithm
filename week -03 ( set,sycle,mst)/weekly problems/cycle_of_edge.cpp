#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
int parent[N], rnk[N];

void make_set(int n)
{
    for (int i = 0; i <= n; i++)
    {
        parent[i] = i;
        rnk[i] = 0;
    }
}

int find_parent(int x)
{
    if (parent[x] != x)
        parent[x] = find_parent(parent[x]);
    return parent[x];
}

bool unite(int a, int b)
{
    a = find_parent(a);
    b = find_parent(b);
    if (a == b)
        return false;
    if (rnk[a] < rnk[b])
        swap(a, b);
    parent[b] = a;
    if (rnk[a] == rnk[b])
        rnk[a]++;
    return true;
}

int main()
{
    int n, m;
    cin >> n >> m;

    make_set(n);
    int edgeCycle = 0;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        if (!unite(u, v))
        {
            edgeCycle++;
        }
    }

    cout << edgeCycle << endl;
    return 0;
}
