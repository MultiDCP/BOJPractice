#include <bits/stdc++.h>
using namespace std;
int n, m, cc;
vector<int> g[1001];
int vis[1001];
queue<int> q;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    for(int i=1; i<=n; i++){
        if(vis[i] == 1) continue;
        vis[i] = 1;
        cc++;
        for(int j=0; j<g[i].size(); j++){
            q.push(g[i][j]);
        }
        while(!q.empty()){
            int v = q.front();
            q.pop();
            if(vis[v] == 1) continue;
            vis[v] = 1;
            for(int j=0; j<g[v].size(); j++){
                q.push(g[v][j]);
            }
        }
    }
    cout << cc;

    return 0;
}