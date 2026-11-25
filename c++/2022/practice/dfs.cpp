#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second // pair에서 first, second를 줄여쓰기 위해 사용

int board[502][502] =
{{1,1,1,0,1,0,0,0,0,0},
 {1,0,1,0,1,0,0,0,0,0},
 {1,1,1,0,1,0,0,0,0,0},
 {1,1,0,0,1,0,0,0,0,0},
 {0,1,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0}}; // 1이 파란 칸, 0이 빨간 칸에 대응
bool vis[502][502]; // 방문했는지 여부 저장
int n = 7, m = 10; //행렬 길이
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1}; // 인접한 칸의 좌표

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    stack<pair<int, int>> s;
    vis[0][0] = 1; // (0, 0) 방문 표시
    s.push({0, 0});
    while(!s.empty()){
        auto cur = s.top();
        cout << '(' << cur.X << ',' << cur.Y << ") -> ";
        s.pop();
        for(int dir = 0; dir < 4; ++dir){
            // 현 노드 상하좌우의 좌표를 저장함
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            
            // 만약 배열의 크기를 벗어나게 된다면 넘어감
            if(nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            
            // 만약 방문한 노드거나 빨간색 칸이면 넘어감
            if(vis[nx][ny] || board[nx][ny] != 1)
                continue;
            
            // 모든 조건을 통과했으면 방문 표시 후 큐에 집어넣음
            vis[nx][ny] = 1;
            s.push({nx, ny}); 
        }
    }

    return 0;
}

/* 출력되는 방문 순서는 상/하/좌/우 중에
어디를 먼저 스택에 넣느냐에 따라 다를 수 있음 */
