#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;
char grid[MAXN][MAXN];
bool visited[MAXN][MAXN];
pair<int, int> parent[MAXN][MAXN];
vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
int n, m;
bool isValid(int i, int j)
{
    return i >= 0 && i < n && j >= 0 && j < m && grid[i][j] != '#' && !visited[i][j];
}
void bfs(int startX, int startY, int destX, int destY)
{
    queue<pair<int, int>> q;
    q.push({startX, startY});
    visited[startX][startY] = true;
    parent[startX][startY] = {-1, -1};
    while (!q.empty())
    {
        pair<int, int> current = q.front();
        q.pop();
        int ci = current.first;
        int cj = current.second;
        if (ci == destX && cj == destY)
        {
            pair<int, int> temp = {ci, cj};
            while (temp != make_pair(-1, -1))
            {
                if (grid[temp.first][temp.second] != 'R' && grid[temp.first][temp.second] != 'D')
                {
                    grid[temp.first][temp.second] = 'X';
                }
                temp = parent[temp.first][temp.second];
            }
            break;
        }
        for (int k = 0; k < 4; k++)
        {
            int ni = ci + directions[k].first;
            int nj = cj + directions[k].second;
            if (isValid(ni, nj))
            {
                visited[ni][nj] = true;
                parent[ni][nj] = {ci, cj};
                q.push({ni, nj});
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    int startX = -1, startY = -1, destX = -1, destY = -1;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 'R')
            {
                startX = i;
                startY = j;
            }
            else if (grid[i][j] == 'D')
            {
                destX = i;
                destY = j;
            }
        }
    }
    if (startX != -1 && startY != -1 && destX != -1 && destY != -1)
    {
        bfs(startX, startY, destX, destY);
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                cout << grid[i][j];
            }
            cout << endl;
        }
    }
    else
    {
        for (int i = 0; i < n; ++i)
        {
            cout << grid[i] << endl;
        }
    }
    return 0;
}