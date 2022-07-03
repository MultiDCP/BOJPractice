#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
const int posX[4] = {1, 0, -1, 0};
const int posY[4] = {0, 1, 0, -1};
int n, maxH, maxSafe;
int arr[100][100];
int vis[100][100];
queue<pair<int, int>> q;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++){
            cin >> arr[i][j];
            if(max(maxH, arr[i][j]) == arr[i][j])
                maxH = arr[i][j];
        }

    for(int i=0; i<maxH; i++){
        memset(vis, 0, sizeof(vis));
        int tmpSafe = 0;
        for(int j=0; j<n; j++){
            for(int k=0; k<n; k++){
                if(vis[j][k] > 0 || arr[j][k] <= i) continue;
                tmpSafe++;
                vis[j][k] = 1;
                q.push({j, k});

                while(!q.empty()){
                    auto pos = q.front();
                    q.pop();
                    for(int l=0; l<4; l++){
                        int dx = pos.X + posX[l];
                        int dy = pos.Y + posY[l];
                        if(dx < 0 || dx >= n || dy < 0 || dy >= n) continue;
                        if(vis[dx][dy] > 0 || arr[dx][dy] <= i) continue;
                        vis[dx][dy] = 1;
                        q.push({dx, dy});
                    }
                }
            }
        }

        if(max(maxSafe, tmpSafe) == tmpSafe)
            maxSafe = tmpSafe;
    }
    cout << maxSafe;
    return 0;
}