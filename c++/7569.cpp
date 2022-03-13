#include <bits/stdc++.h>
using namespace std;

int arr[100][100][100];
int needDay[100][100][100];
// 방향을 미리 잡아준다
int posX[6] = {1, 0, -1, 0, 0, 0};
int posY[6] = {0, 1, 0, -1, 0, 0};
int posZ[6] = {0, 0, 0, 0, 1, -1};
queue<tuple<int, int, int>> q;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 모든 기본 배열을 -1로 초기화시킨다.
    for(int i=0; i<100; i++){
        for(int j=0; j<100; j++){
            for(int k=0; k<100; k++){
                arr[i][j][k] = -1;
                needDay[i][j][k] = -1;
            }
        }
    }

    int n, m, h;
    cin >> m >> n >> h;

    for(int i=0; i<h; i++){
        for(int j=0; j<n; j++){
            for(int k=0; k<m; k++){
                int temp;
                cin >> temp;
                arr[i][j][k] = temp;
            }
        }
    }

    // 모든 토마토가 이미 익어있는 경우를 따로 판단한다
    bool isAllRiped = true;
    for(int i=0; i<h; i++){
        for(int j=0; j<n; j++){
            for(int k=0; k<m; k++)
                // 만약 안 익은 토마토가 하나라도 있다면 계속 진행할 수 있도록 한다
                if(arr[i][j][k] == 0) isAllRiped = false;
        }
    }
    if(isAllRiped){ // 모든 토마토가 이미 익은 경우엔 0을 출력하고 종료한다
        cout << 0;
        return 0;
    }

    // 익은 토마토의 좌표들을 큐에 먼저 집어넣는다.
    // 주변 토마토들은 동시에 익게 되므로 익은 토마토를 미리 큐에 넣어줘야 정상적으로 계산이 된다
    // 이후 먼저 안 익은 토마토에 방문할 경우 그 값이 최솟값(최소 일수)이 된다
    for(int i=0; i<h; i++){
        for(int j=0; j<n; j++){
            for(int k=0; k<m; k++){
                if(arr[i][j][k] != 1 || needDay[i][j][k] > 0) continue;
                needDay[i][j][k] = 0; // 이미 익은 토마토들은 0일이 필요하므로 0을 넣는다
                q.push({i, j, k});
            }
        }
    }

    while(!q.empty()){ // BFS를 굴린다.
        auto cur = q.front();
        q.pop();

        for(int i=0; i<6; i++){
            int cz = get<0>(cur); int cx = get<1>(cur); int cy = get<2>(cur);
            int nx = cx + posX[i];
            int ny = cy + posY[i];
            int nz = cz + posZ[i];

            if(nx < 0 || nx >= n || ny < 0 || ny >= m || nz < 0 || nz >= h) continue;
            if(arr[nz][nx][ny] != 0 || needDay[nz][nx][ny] > 0) continue;
            needDay[nz][nx][ny] = needDay[cz][cx][cy] + 1;
            q.push({nz, nx, ny});
        }
    }

    int result = -2; // 최대값 판정을 위해 최대한 작은 값을 넣는다
    int cannotRiped = false; // 익을 수 없는 경우를 판단한다

    // 배열을 완전 탐색한다. 최악의 경우도 1000000회만 굴러가므로 TC에 걸리지 않는다.
    for(int i=0; i<h; i++){
        for(int j=0; j<n; j++){
            for(int k=0; k<m; k++){
                // 만약 익지 않았는데 방문을 한 적이 없다면 익을 수 없다고 따로 표시한다
                if(arr[i][j][k] == 0 && needDay[i][j][k] < 0) cannotRiped = true;
                if(needDay[i][j][k] > result)
                    result = needDay[i][j][k]; // 그 외 경우 거리의 최대값을 찾는다
            }
        }
    }
    if(cannotRiped) cout << "-1\n";
    else cout << result << "\n";

    return 0;
}

/*
오답도 아닌 오답 정리
3차원 배열에서도 BFS는 쓸 수 있다
하지만 나 자신이 나를 씹억까했다
모든 테스트 케이스와 반례를 통과하는 한이 있더라도
코드 디버깅 제대로 안하면 틀릴 수 있는 아주 좋은 예시
본인이 제대로 풀었다고 생각했는데 뭔가 문제가 있다면
모든 코드가 맞다고 생각하지 말고 제대로 소리내어 쳐읽어봐라 좀
어떻게 등호 하나 안쳐가지고 1시간동안 스스로 억까를 당하냐
*/