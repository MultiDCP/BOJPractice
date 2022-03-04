#include <bits/stdc++.h>
using namespace std;

int arr[100][100][100];
int needDay[100][100][100];
int posX[6] = {1, 0, -1, 0, 0, 0};
int posY[6] = {0, 1, 0, -1, 0, 0};
int posZ[6] = {0, 0, 0, 0, 1, -1};
queue<tuple<int, int, int>> q;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

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

    bool isAllRiped = true;
    for(int i=0; i<h; i++){
        for(int j=0; j<n; j++){
            for(int k=0; k<m; k++)
                if(arr[i][j][k] == 0) isAllRiped = false;
        }
    }
    if(isAllRiped){
        cout << 0;
        return 0;
    }

    // 익은 거 큐에 집어넣기
    for(int i=0; i<h; i++){
        for(int j=0; j<n; j++){
            for(int k=0; k<m; k++){
                if(arr[i][j][k] != 1 || needDay[i][j][k] > 0) continue;
                needDay[i][j][k] = 0;
                q.push({i, j, k});
            }
        }
    }

    while(!q.empty()){
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

    int result = -2;
    int cannotRiped = false;

    for(int i=0; i<h; i++){
        for(int j=0; j<n; j++){
            for(int k=0; k<m; k++){
                if(arr[i][j][k] == 0 && needDay[i][j][k] < 0) cannotRiped = true;
                if(needDay[i][j][k] > result)
                    result = needDay[i][j][k];
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