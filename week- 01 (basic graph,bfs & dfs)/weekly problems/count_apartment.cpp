#include <bits/stdc++.h>
using namespace std;
const int MAX = 1000;
char building[MAX][MAX];
bool vis[MAX][MAX];
vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
int N, M;
bool isValid(int x, int y)
{
    if (x >= 0 && x < N && y >= 0 && y < M && building[x][y] == '.' && !vis[x][y])
        return true;
    return false;
}
void dfs(int x, int y)
{
    vis[x][y] = true;
    for (int i = 0; i < 4; i++)
    {
        int newX = x + d[i].first;
        int newY = y + d[i].second;
        if (isValid(newX, newY))
        {
            dfs(newX, newY);
        }
    }
}
int countApartments(int N, int M)
{
    int ct = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (building[i][j] == '.' && !vis[i][j])
            {
                dfs(i, j);
                ct++;
            }
        }
    }
    return ct;
}
int main()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> building[i][j];
            vis[i][j] = false;
        }
    }
    int result = countApartments(N, M);
    cout << result << endl;
    return 0;
}