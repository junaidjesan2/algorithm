#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000;
int N, M;
char building[MAX][MAX];
bool visited[MAX][MAX];
vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
bool isValid(int x, int y)
{
    if (x >= 0 && x < N && y >= 0 && y < M && building[x][y] != '#')
        return true;
    return false;
}
bool canReach(pair<int, int> start, pair<int, int> end)
{
    queue<pair<int, int>> q;
    q.push(start);
    visited[start.first][start.second] = true;
    while (!q.empty())
    {
        pair<int, int> current = q.front();
        q.pop();
        if (current.first == end.first && current.second == end.second)
        {
            return true;
        }
        for (int i = 0; i < 4; i++)
        {
            int newX = current.first + d[i].first;
            int newY = current.second + d[i].second;

            if (isValid(newX, newY) && !visited[newX][newY])
            {
                visited[newX][newY] = true;
                q.push({newX, newY});
            }
        }
    }
    return false;
}
int main()
{
    cin >> N >> M;
    pair<int, int> roomA, roomB;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> building[i][j];
            if (building[i][j] == 'A')
            {
                roomA = {i, j};
            }
            else if (building[i][j] == 'B')
            {
                roomB = {i, j};
            }
        }
    }
    memset(visited, false, sizeof(visited));
    if (canReach(roomA, roomB))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}