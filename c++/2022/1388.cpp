#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
const int dx[2] = {1, -1};
const int dy[2] = {1, -1};
int n, m, res;
char arr[51][51];
int vis[51][51];
queue<pair<int, int>> q;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for(int i=0; i<=50; i++)
        for(int j=0; j<=50; j++)
            vis[i][j] = -1;
    
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++){
            cin >> arr[i][j];
            vis[i][j] = 0;
        }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(vis[i][j] != 0) continue;
            else{
                vis[i][j] = 1;
                res++;
                q.push({i, j});

                while(!q.empty()){
                    auto k = q.front();
                    q.pop();
                    if(arr[k.X][k.Y] == '-'){
                        for(int i=0; i<2; i++){
                            int newX = k.Y + dx[i];
                            if(newX < 0 || newX > m) continue;
                            if(vis[k.X][newX] != 0 || arr[k.X][newX] == '|') continue;
                            vis[k.X][newX] = 1;
                            q.push({k.X, newX});
                        }
                    }
                    else if(arr[k.X][k.Y] == '|'){
                        for(int i=0; i<2; i++){
                            int newY = k.X + dy[i];
                            if(newY < 0 || newY > n) continue;
                            if(vis[newY][k.Y] != 0 || arr[newY][k.Y] == '-') continue;
                            vis[newY][k.Y] = 1;
                            q.push({newY, k.Y});
                        }
                    }
                }
            }
        }
    }
    cout << res;

    return 0;
}

/*
visit을 변수명으로 쓰지 마라... 백준 컴파일러에서 삐꾸난다
답은 틀렸다고 나오는데 반례 집어넣는 거마다 잘 들어가면
일단 n과 m을 잘못 쓰진 않았는지를 먼저 확인하라

vis를 -1로 초기화를 할 필요가 없었나?
dx, dy를 하나로 통합해서 해도 됐을듯?
*/