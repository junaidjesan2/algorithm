#include <bits/stdc++.h>
using namespace std;

bool same_component(int n, int m, vector<string> &grid, pair<int, int> start, pair<int, int> end)
{
    int s1 = start.first, d1 = start.second;
    int s2 = end.first, d2 = end.second;

        if (grid[s1][d1] == '-' || grid[s2][d2] == '-')
    {
        return false;
    }

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    queue<pair<int, int>> q;
    q.push({s1, d1});
    visited[s1][d1] = true;

    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};

    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();

        if (x == s2 && y == d2)
            return true;

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && grid[nx][ny] == '.')
            {
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }

    return false;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    for (int i = 0; i < n; i++)
    {
        cin >> grid[i];
    }

    int s1, d1, s2, d2;
    cin >> s1 >> d1;
    cin >> s2 >> d2;

    if (same_component(n, m, grid, {s1, d1}, {s2, d2}))
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}
