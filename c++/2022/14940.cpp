#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
const int posX[4] = {1, 0, -1, 0};
const int posY[4] = {0, 1, 0, -1};
int n, m, stX, stY;
int arr[1000][1000];
int dis[1000][1000];
queue<pair<int, int>> q;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    memset(dis, -1, sizeof(dis));
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 2){
                stX = i;
                stY = j;
            }
            else if(arr[i][j] == 0)
                dis[i][j] = 0;
        }

    dis[stX][stY] = 0;
    q.push({stX, stY});
    while(!q.empty()){
        auto k = q.front();
        q.pop();

        for(int i=0; i<4; i++){
            int dx = k.X + posX[i];
            int dy = k.Y + posY[i];
            if(dx < 0 || dx >= n || dy < 0 || dy >= m) continue;
            if(dis[dx][dy] >= 0 || arr[dx][dy] == 0) continue;
            dis[dx][dy] = dis[k.X][k.Y] + 1;
            q.push({dx, dy});
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++)
            cout << dis[i][j] << " ";
        cout << "\n";
    }

    return 0;
}