#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int pir[N];

void Dsu(int n)
{
    for (int i = 0; i < n; i++)
    {
        pir[i] = -1;
    }
    pir[1] = 2;
    pir[2] = 3;
    pir[5] = 6;
    pir[6] = 7;
}
int find(int node)
{
    if (pir[node] == -1)
    {
        return node;
    }
    int leader = find(pir[node]);
    pir[node] = leader;
    return leader;
}
void dsu_union(int node1, int node2)
{
    int leaderA = find(node1);
    int leaderB = find(node2);
    pir[leaderA] = leaderB;
}
int main()
{
    Dsu(8);
    dsu_union(1, 5);
    cout << find(1) << endl;

    return 0;
}