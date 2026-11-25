#include <iostream>
#include <queue>
#include <utility>

#define X first
#define Y second

using namespace std;

int arr[500][500];
bool visited[500][500];
queue<pair<int, int>> q;
int dirX[4] = {1, 0, -1, 0};
int dirY[4] = {0, 1, 0, -1};

int picCount = 0, maxSize = 0;

int main(void)
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
            visited[i][j] = false;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 1 && !visited[i][j])
            {
                int size = 0;
                picCount++;
                size++;
                q.push({i, j});
                visited[i][j] = true;
                while (!q.empty())
                {
                    auto k = q.front();
                    q.pop();
                    for (int l = 0; l < 4; l++)
                    {
                        int newX = k.X + dirX[l];
                        int newY = k.Y + dirY[l];
                        if (newX < 0 || newX >= n || newY < 0 || newY >= m) continue;
                        if (visited[newX][newY] || arr[newX][newY] == 0) continue;
                        size++;
                        q.push({newX, newY});
                        visited[newX][newY] = true;
                    }
                }
                if (maxSize <= size) maxSize = size;
            }
        }
    }

    cout << picCount << "\n" << maxSize << "\n";
    return 0;
}