#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int arr[100][100];
int dis[100][100];
int posX[4] = {1, 0, -1, 0};
int posY[4] = {0, 1, 0, -1};

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        for(int j=0; j<m; j++){
            arr[i][j] = int(s[j] - '0');
        }
        fill(dis[i], dis[i]+m, -1);
    }
    queue<pair<int, int>> q;

    q.push({0, 0});
    dis[0][0] = 1;

    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        
        for(int i=0; i<4; i++){
            int nx = cur.X + posX[i];
            int ny = cur.Y + posY[i];

            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(arr[nx][ny] == 0 || dis[nx][ny] != -1) continue;

            dis[nx][ny] = dis[cur.X][cur.Y] + 1;
            q.push({nx, ny});
        }
    }

    cout << dis[n-1][m-1];

    return 0;
}

/*
다 좋은데
dis가 visit을 대신할 수 있다는 점 알아두자
*/