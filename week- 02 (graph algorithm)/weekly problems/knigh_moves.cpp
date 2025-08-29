#include <bits/stdc++.h>
using namespace std;
const int MAX = 100;
vector<pair<int, int>> d = {{-2, -1}, {-1, -2}, {1, -2}, {2, -1}, {-2, 1}, {-1, 2}, {1, 2}, {2, 1}};
bool vis[MAX][MAX];
int N, M;
bool isValid(int x, int y)
{
    if (x >= 0 && x < N && y >= 0 && y < M)
        return true;
    else
        return false;
}
int minKnightSteps(pair<int, int> knight, pair<int, int> queen)
{
    queue<pair<pair<int, int>, int>> q;
    q.push({knight, 0});
    vis[knight.first][knight.second] = true;
    while (!q.empty())
    {
        pair<pair<int, int>, int> cr = q.front();
        q.pop();
        if (cr.first == queen)
        {
            return cr.second;
        }
        for (int i = 0; i < 8; i++)
        {
            int newX = cr.first.first + d[i].first;
            int newY = cr.first.second + d[i].second;
            if (isValid(newX, newY) && !vis[newX][newY])
            {
                q.push({{newX, newY}, cr.second + 1});
                vis[newX][newY] = true;
            }
        }
    }
    return -1;
}
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        cin >> N >> M;
        pair<int, int> knight, queen;
        cin >> knight.first >> knight.second;
        cin >> queen.first >> queen.second;
        memset(vis, false, sizeof(vis));
        int result = minKnightSteps(knight, queen);
        cout << result << endl;
    }
    return 0;
}