#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int n, l;
int dis[300][300];
queue<pair<int, int>> q;
int posX[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int posY[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i=0; i<n; i++){
        cin >> l;
        for(int j=0; j<l; j++)
            memset(dis[j], -1, sizeof(int)*l);
        int fromX, fromY, toX, toY;
        cin >> fromX >> fromY >> toX >> toY;
        if(fromX == toX && fromY == toY){
            cout << 0 << "\n";
            continue;
        }
        q.push({fromX, fromY});
        dis[fromX][fromY] = 0;
        while(!q.empty()){
            auto cur = q.front();
            q.pop();
            for(int i=0; i<8; i++){
                int nx = cur.X + posX[i];
                int ny = cur.Y + posY[i];
                
                if(nx < 0 || nx >= l || ny < 0 || ny >= l) continue;
                if(dis[nx][ny] > 0) continue;
                dis[nx][ny] = dis[cur.X][cur.Y] + 1;
                q.push({nx, ny});
            }
        }
        cout << dis[toX][toY] << "\n";
    }

    return 0;
}