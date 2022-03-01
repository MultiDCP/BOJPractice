#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int arr[50][50];
int vis[50][50];
int posX[4] = {1, 0, -1, 0};
int posY[4] = {0, 1, 0, -1};

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    for(int i=0; i<t; i++){
        int m, n, k;
        int count = 0;
        cin >> m >> n >> k;
        for(int j=0; j<k; j++){
            int x, y;
            cin >> x >> y;
            arr[y][x] = 1;
        }

        queue<pair<int, int>> q;
        for(int j=0; j<n; j++){
            for(int k=0; k<m; k++){
                if(arr[j][k] == 0 || vis[j][k] == 1) continue;
                else{
                    count++;
                    q.push({j, k});
                    vis[j][k] = 1;

                    while(!q.empty()){
                        auto cur = q.front();
                        q.pop();

                        for(int l=0; l<4; l++){
                            int nx = cur.X + posX[l];
                            int ny = cur.Y + posY[l];

                            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                            if(vis[nx][ny] || arr[nx][ny] == 0) continue;

                            vis[nx][ny] = 1;
                            q.push({nx, ny});
                        }
                    }
                }
            }
        }
        cout << count << "\n";
        for(int j=0; j<50; j++){
            for(int k=0; k<50; k++){
                arr[j][k] = 0;
                vis[j][k] = 0;
            }
        }
    }

    return 0;
}