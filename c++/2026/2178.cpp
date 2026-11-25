#include <iostream>
#include <queue>
#include <utility>
#include <string>

#define X first
#define Y second

using namespace std;

char arr[100][100];
int visited[100][100];
queue<pair<int, int>> q;
int dirX[4] = {1, 0, -1, 0};
int dirY[4] = {0, 1, 0, -1};

int main(void)
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++)
        {
            arr[i][j] = s[j];
            visited[i][j] = 0;
        }
    }

    visited[0][0] = 1;
    q.push({0, 0});
    while(!q.empty())
    {
        auto k = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int newX = k.X + dirX[i];
            int newY = k.Y + dirY[i];

            if (newX < 0 || newX >= n || newY < 0 || newY >= m) continue;
            if (arr[newX][newY] == '0' || visited[newX][newY] != 0) continue;

            visited[newX][newY] = visited[k.X][k.Y] + 1;
            q.push({newX, newY});
        }
    }

    cout << visited[n-1][m-1] << "\n";
    return 0;
}