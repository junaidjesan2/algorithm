#include <bits/stdc++.h>
using namespace std;
const int MAX = 1000;
char building[MAX][MAX];
bool visited[MAX][MAX];
vector<int> aptSize;
vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
int N, M;
bool isValid(int x, int y)
{
    if (x >= 0 && x < N && y >= 0 && y < M && building[x][y] == '.' && !visited[x][y])
        return true;
    return false;
}
void dfs(int x, int y, int &roomCnt)
{
    visited[x][y] = true;
    roomCnt++;
    for (int i = 0; i < 4; i++)
    {
        int newX = x + d[i].first;
        int newY = y + d[i].second;
        if (isValid(newX, newY))
        {
            dfs(newX, newY, roomCnt);
        }
    }
}
int main()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> building[i][j];
            visited[i][j] = false;
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (building[i][j] == '.' && !visited[i][j])
            {
                int roomCnt = 0;
                dfs(i, j, roomCnt);
                aptSize.push_back(roomCnt);
            }
        }
    }
    sort(aptSize.begin(), aptSize.end());
    for (int size : aptSize)
    {
        cout << size << " ";
    }
    if (aptSize.empty())
    {
        cout << 0;
    }
    return 0;
}