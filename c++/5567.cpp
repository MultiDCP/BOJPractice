#include <bits/stdc++.h>
using namespace std;
#define V first
#define D second
int n, m, res;
vector<int> g[501];
int vis[501];
queue<pair<int, int>> q;
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
        q.push({g[1][i], 1});

    while(!q.empty()){
        auto k = q.front();
        q.pop();
        if(vis[k.V] == 1) continue;
        vis[k.V] = 1;
        if(k.D <= 2) res++;
        for(int i=0; i<g[k.V].size(); i++)
            q.push({g[k.V][i], k.D+1});
    }
    cout << res;

    return 0;
}