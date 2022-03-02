#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int arr[1000][1000];
int needDay[1000][1000];
int posX[4] = {1, 0, -1, 0};
int posY[4] = {0, 1, 0, -1};

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    for(int i=0; i<1000; i++){
        for(int j=0; j<1000; j++){
            arr[i][j] = -1; needDay[i][j] = -1;
        }
    }
    
    int n, m;
    cin >> m >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int tmp;
            cin >> tmp;
            arr[i][j] = tmp;
        }
    }
    
    queue<pair<int, int>> q;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(arr[i][j] != 1) continue;
            
            q.push({i, j});
            needDay[i][j] = 0;
        }
    }
    
    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        
        for(int i=0; i<4; i++){
            int nx = cur.X + posX[i];
            int ny = cur.Y + posY[i];
            
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(arr[nx][ny] != 0 || needDay[nx][ny] > 0) continue;
            needDay[nx][ny] = needDay[cur.X][cur.Y] + 1;
            q.push({nx, ny});
        }
    }
    
    int maxDay = -1;
    bool isAllRiped = true;
    bool CannotRiped = false;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(needDay[i][j] > 0)
                isAllRiped = false;
            if(arr[i][j] == 0 && needDay[i][j] == -1)
                CannotRiped = true;
            if(maxDay < needDay[i][j])
                maxDay = needDay[i][j];
        }
    }
    
    if(CannotRiped)
        cout << -1;
    else if(isAllRiped)
        cout << 0;
    else
        cout << maxDay;
    
    return 0;
}

/*
오답 이유
1. BFS를 이렇게도 쓸 수 있군요! 2탄
이런 문제 같은 경우는 BFS의 시작 조건을 충족하는 노드가 여러 개인 경우가 있는데
이럴 경우 각 노드에서 BFS를 한 번씩 돌고 최저값을 찾는 것이 아니라
딱 한 번 BFS를 돌기 전에 시작 조건을 충족하는 노드를 전부 큐에 때려박고 시작하면 된다
이러면 결국 최저값에 해당하는 친구는 숨바꼭질 문제처럼 먼저 도착해서 자리를 잡을 수 있을 것이고
모든 노드들을 한 번씩만 돌게 되므로 시간복잡도 역시 O(N)이 나온다
이러한 점 때문에 시간 초과 오답을 내게 되었다.
2. 96%에서 틀리고 맞왜틀을 시전하게 된 이유는
모든 토마토가 익었을 경우와 익지 못할 경우에 대해서 조건분기 순서를 다르게 했다
전부 0만 있을 경우 isAllRiped가 true인 상태가 유지되어(정확히는 이를 false로 바꾸는 조건분기 안에 들어가지 못하여)
이에 대한 조건을 따로 만들어주거나 모든 토마토가 익지는 못할 경우를 먼저 갈랐어야 했다
하 그래도 답지도 안 보고 잘 풀었다
*/