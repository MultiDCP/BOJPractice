#include <bits/stdc++.h>
using namespace std;
int n, m, r;
int cnt = 1;
vector<int> g[100001];
int vis[100001];
queue<int> q;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> r;
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    for(int i=1; i<=n; i++)
        sort(g[i].begin(), g[i].end());

    vis[r] = cnt;
    for(int i=0; i<g[r].size(); i++)
        q.push(g[r][i]);

    while(!q.empty()){
        int t = q.front();
        q.pop();
        if(vis[t] > 0) continue;
        vis[t] = ++cnt;
        for(int i=0; i<g[t].size(); i++)
            q.push(g[t][i]);
    }

    for(int i=1; i<=n; i++)
        cout << vis[i] << "\n";

    return 0;
}