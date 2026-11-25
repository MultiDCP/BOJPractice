#include <bits/stdc++.h>
using namespace std;
#define VAL first
#define CNT second
int n, m;
vector<int> g[101];
bool vis[101];
queue<pair<int, int>> q;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for(int i=0; i<n; i++){
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
    }
    for(int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }

    q.push({1, 0});
    while(!q.empty()){
        auto k = q.front();
        q.pop();
        vis[k.VAL] = true;

        if(k.VAL == 100){
            cout << k.CNT << "\n";
            return 0;
        }

        for(int i=1; i<=6; i++){
            int dv = k.VAL + i;
            if(dv > 100 || vis[dv]) continue;
            if(g[dv].empty())
                q.push({dv, k.CNT+1});
            else
                q.push({g[dv][0], k.CNT+1});
        }
    }

    return 0;
}