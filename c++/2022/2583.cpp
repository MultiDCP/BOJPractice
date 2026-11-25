#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int arr[100][100];
int vis[100][100];
int posX[4] = {1, 0, -1, 0};
int posY[4] = {0, 1, 0, -1};
queue<pair<int, int>> q;
vector<int> counts;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int m, n, k;
    cin >> m >> n >> k;
    for(int i=0; i<k; i++){
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for(int j=x1; j<x2; j++)
            for(int l=y1; l<y2; l++)
                arr[l][j] = 1;
    }

    int total = 0;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(arr[i][j] != 0 || vis[i][j] > 0) continue;
            ++total;
            vis[i][j] = 1;
            q.push({i, j});

            int area = 0;
            while(!q.empty()){
                auto cur = q.front();
                ++area;
                q.pop();
                for(int l=0; l<4; l++){
                    int nx = cur.X + posX[l];
                    int ny = cur.Y + posY[l];
                    if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                    if(arr[nx][ny] != 0 || vis[nx][ny] > 0) continue;
                    vis[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
            counts.push_back(area);
        }
    }
    sort(counts.begin(), counts.end());
    cout << total << "\n";
    for(int i=0; i<counts.size(); i++)
        cout << counts[i] << " ";

    return 0;
}