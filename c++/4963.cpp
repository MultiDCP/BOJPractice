#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int w, h;
const int posX[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
const int posY[8] = {1, 1, 1, 0, 0, -1, -1, -1};
int arr[51][51];
int vis[51][51];
queue<pair<int, int>> q;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while(true){
        cin >> w >> h;
        if(w == 0 && h == 0) return 0;
        for(int i=0; i<h; i++)
            for(int j=0; j<w; j++)
                cin >> arr[i][j];

        int res = 0;
        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                if(arr[i][j] == 0 || vis[i][j] > 0) continue;
                vis[i][j] = 1;
                res++;
                q.push({j, i});

                while(!q.empty()){
                    auto k = q.front();
                    q.pop();
                    for(int l=0; l<8; l++){
                        int dx = k.X + posX[l];
                        int dy = k.Y + posY[l];
                        if(dx < 0 || dx >= w || dy < 0 || dy >= h) continue;
                        if(arr[dy][dx] == 0 || vis[dy][dx] > 0) continue;
                        vis[dy][dx] = 1;
                        q.push({dx, dy});
                    }
                }
            }
        }

        cout << res << "\n";
        memset(arr, 0, sizeof(arr));
        memset(vis, 0, sizeof(vis));
    }

    return 0;
}