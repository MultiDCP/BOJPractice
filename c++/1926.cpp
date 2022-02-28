#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int board[500][500];
int vis[500][500];
int posX[4] = {1, 0, -1, 0};
int posY[4] = {0, 1, 0, -1};

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    int count = 0;
    int max = 0;
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int tmp;
            cin >> tmp;
            board[i][j] = tmp;
        }
    }

    queue<pair<int, int>> q;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(board[i][j] == 1 && vis[i][j] != 1){
                count++;
                int area = 1;
                vis[i][j] = 1;
                q.push({i, j});
                while(!q.empty()){
                    auto cur = q.front();
                    q.pop();
                    for(int k=0; k<4; k++){
                        int nx = cur.X + posX[k];
                        int ny = cur.Y + posY[k];

                        if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                        if(vis[nx][ny] == 1 || board[nx][ny] == 0) continue;
                        area++;
                        vis[nx][ny] = 1;
                        q.push({nx, ny});
                    }
                }
                if(max < area)
                    max = area;
            }
            else
                continue;
        }
    }

    cout << count << "\n" << max << "\n";

    return 0;
}

/*
컴파일 에러 및 오답이 한 번 나왔던 이유
visit이라는 친구가 이미 어느 헤더파일에 존재했나보다
그래서 모호하다고 안 된다고 온 거 같다.
또한 오답이 나온 이유는
'그림이 0개일 경우 최대 넓이는 0이다' 라고 표시한 부분에서
제대로 된 교차 검증을 하려고 생각해놓고 안해서 틀리게 되었다.
테스트 케이스 좀 똑바로 넣자
*/