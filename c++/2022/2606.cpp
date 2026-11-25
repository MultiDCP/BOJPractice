#include <bits/stdc++.h>
using namespace std;
int n, m, res;
int vis[101];
vector<int> g[101];
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

    vis[1] = 1;
    for(int i=0; i<g[1].size(); i++)
        q.push(g[1][i]);

    while(!q.empty()){
        int v = q.front();
        q.pop();
        if(vis[v] == 1) continue;
        vis[v] = 1;
        res++;
        for(int i=0; i<g[v].size(); i++)
            q.push(g[v][i]);
    }
    cout << res;

    return 0;
}