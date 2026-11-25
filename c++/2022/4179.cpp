#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
const int posX[4] = {1, 0, -1, 0};
const int posY[4] = {0, 1, 0, -1};
int r, c;
char arr[1001][1001];
int vis[1001][1001];
queue<pair<int, int>> q;
queue<pair<int, int>> fq;

void FireBFS(){
    while(true){
        auto fk = fq.front();
        fq.pop();
        if(fk.X == -1 && fk.Y == -1) break;

        for(int i=0; i<4; i++){
            int dx = fk.X + posX[i];
            int dy = fk.Y + posY[i];

            if(dx < 0 || dx >= r || dy < 0 || dy >= c) continue;
            if(arr[dx][dy] != '.') continue;
            arr[dx][dy] = 'F';
            fq.push({dx, dy});
        }
    }
    fq.push({-1, -1});
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> r >> c;
    memset(vis, -1, sizeof(vis));
    int jx, jy;
    for(int i=0; i<r; i++)
        for(int j=0; j<c; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 'J'){
                jx = i;
                jy = j;
            }
            else if(arr[i][j] == 'F')
                fq.push({i, j});
        }

    fq.push({-1, -1});
    vis[jx][jy] = 0;
    q.push({jx, jy});

    int resX, resY;
    bool isEscaped = false;

    while(!q.empty() && !isEscaped){
        auto k = q.front();
        q.pop();

        if((k.X == jx && k.Y == jy) || !q.empty() && vis[k.X][k.Y] < vis[q.front().X][q.front().Y])
            FireBFS();

        if(arr[k.X][k.Y] == 'F') continue;

        for(int i=0; i<4; i++){
            int dx = k.X + posX[i];
            int dy = k.Y + posY[i];

            if(dx < 0 || dx >= r || dy < 0 || dy >= c){
                resX = k.X;
                resY = k.Y;
                isEscaped = true;
                break;
            }
            if(vis[dx][dy] >= 0) continue;
            if(arr[dx][dy] == 'F' || arr[dx][dy] == '#') continue;
            vis[dx][dy] = vis[k.X][k.Y] + 1;
            q.push({dx, dy});
        }
        
        if(isEscaped) break;
/*
        
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                cout << arr[i][j];
            }
            cout << "\n";
        }
        cout << q.front().X << " " << q.front().Y << "\n\n";
        */
        
    }

    if(!isEscaped)
        cout << "IMPOSSIBLE";
    else
        cout << vis[resX][resY] + 1;

    return 0;
}

/*
풀이에 오래 걸린 이유
문제 알고리즘 생각 자체는 오래 걸리지 않았다
하지만 지훈과 불이 동시에 전진함에 따라
이것들의 전진 타이밍을 잡아주는 것에서 많은 시간이 소요되었다

1. 지훈의 경우가 큐에서 아직 남아있는데 각 노드가 돌아갈 때마다
불의 전진이 진행되어 타이밍 이슈가 생겼다
2. 불이 먼저 전진한 다음 지훈이 전진할 수 있는 경우가 있는지를 보면 되나
지훈을 먼저 이동시킨 뒤, 불을 전진시키고 그 경우에 지훈이 있는지를
파악하는 방식으로 계산하여 특정 경우에 자기 위치에 불이 있음에도
다음 경로를 계산하는 대참사가 발생했다

잘 타는구만! 아주 잘 타!
내 멘탈이
*/