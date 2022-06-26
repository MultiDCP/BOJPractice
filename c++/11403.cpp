#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> g[101];
int res[101][101];
int vis[101];
queue<int> q;
void bfs(int srt){
    memset(vis, 0, sizeof(vis));
    for(int i : g[srt])
        q.push(i);
    
    while(!q.empty()){
        int k = q.front();
        q.pop();
        if(vis[k] > 0) continue;
        vis[k] = 1;
        res[srt][k] = 1;

        for(int i : g[k])
            q.push(i);
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            int t;
            cin >> t;
            if(t == 1){
                g[i].push_back(j);
            }
        }
    }

    for(int i=1; i<=n; i++)
        bfs(i);

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++)
            cout << res[i][j] << " ";
        cout << "\n";
    }

    return 0;
}