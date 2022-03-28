#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int n, normal, blind;
char a[101][101];
int v[101][101];
int posX[4] = {1, 0, -1, 0};
int posY[4] = {0, 1, 0, -1};
queue<pair<int, int>> q;

int bfs(char color){
    int tmp = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(a[i][j] != color || v[i][j] > 0) continue;
            tmp++;
            v[i][j] = 1;
            q.push({i, j});
            while(!q.empty()){
                auto cur = q.front();
                q.pop();
                for(int k=0; k<4; k++){
                    int nx = cur.X + posX[k];
                    int ny = cur.Y + posY[k];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                    if(v[nx][ny] > 0 || color != a[nx][ny]) continue;
                    v[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
        }
    }
    for(int i=0; i<101; i++)
        memset(v[i], 0, sizeof(int)*101);
    return tmp;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin >> a[i][j];

    normal += bfs('R');
    normal += bfs('G');
    normal += bfs('B');

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            if(a[i][j] == 'G')
                a[i][j] = 'R';

    blind += bfs('R');
    blind += bfs('B');

    cout << normal << " " << blind;

    return 0;
}

/*
오답 정리
이런 경우는 어짜피 시간도 공간도 넉넉하니까
걍 다른데 같은 케이스들을 다 똑같이 만들어버리고
BFS를 굴리는 게 정신건강에 이로울 것이다
*/