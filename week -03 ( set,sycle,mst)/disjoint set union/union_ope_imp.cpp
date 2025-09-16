#include <bits/stdc++.h>
using namespace std;
int par[1005];
int u_size[1005];
int find(int a)
{
    if (par[a] == -1)
        return a;

    int led = find(par[a]);
    par[a] = led;
    return led;
}
void dsu_union(int n1, int n2)
{
    int l1 = find(n1);
    int l2 = find(n2);
    if (u_size[l1] >= u_size[l2])
    {
        par[l2] = l1;
        u_size[l1] += u_size[l2];
    }
    else
    {
        par[l1] = l2;
        u_size[l2] += u_size[l1];
    }
}
int main()
{
    memset(par, -1, sizeof(par));
    memset(u_size, 1, sizeof(u_size));
    par[0] = 1;
    par[1] = -1;
    par[2] = 1;
    par[3] = 1;
    par[4] = 5;
    par[5] = 3;
    dsu_union(1, 2);
    for (int i = 0; i < 6; i++)
    {
        cout << par[i] << " ";
    }
    return 0;
}