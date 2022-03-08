#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

char arr[25][25];
int vis[25][25];
int posX[4] = {1, 0, -1, 0};
int posY[4] = {0, 1, 0, -1};

vector<int> counts;
queue<pair<int, int>> q;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        for(int j=0; j<s.length(); j++){
            arr[i][j] = s[j];
        }
    }

    int total = 0;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(arr[i][j] != '1' || vis[i][j] > 0) continue;
            total++;
            vis[i][j] = 1;
            q.push({i, j});

            int count = 0;
            while(!q.empty()){
                auto cur = q.front();
                q.pop(); count++;
                for(int k=0; k<4; k++){
                    int nx = cur.X + posX[k];
                    int ny = cur.Y + posY[k];

                    if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                    if(arr[nx][ny] != '1' || vis[nx][ny] > 0) continue;
                    vis[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
            counts.push_back(count);
        }
    }
    sort(counts.begin(), counts.end());

    cout << total << "\n";

    for(int i=0; i<counts.size(); i++){
        cout << counts[i] << "\n";
    }

    return 0;
}