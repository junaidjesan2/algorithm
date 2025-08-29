#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<string> mat;
vector<vector<bool>> visited;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int bfs(int sx, int sy)
{
    queue<pair<int, int>> q;
    q.push({sx, sy});
    visited[sx][sy] = true;
    int count = 1;

    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m)
            {
                if (!visited[nx][ny] && mat[nx][ny] == '.')
                {
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                    count++;
                }
            }
        }
    }
    return count;
}

int main()
{

    cin >> n >> m;
    mat.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> mat[i];
    }

    visited.assign(n, vector<bool>(m, false));

    int min_area = INT_MAX;
    bool found = false;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == '.' && !visited[i][j])
            {
                int area = bfs(i, j);
                min_area = min(min_area, area);
                found = true;
            }
        }
    }

    if (found)
        cout << min_area << "\n";
    else
        cout << -1 << "\n";

    return 0;
}
