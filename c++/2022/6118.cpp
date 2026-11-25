#include <bits/stdc++.h>
using namespace std;
#define V first
#define D second
int n, m, maxD;
vector<int> maxV;
vector<int> g[20001];
int vis[20001];
queue<pair<int, int>> q;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    memset(vis, -1, sizeof(vis));
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vis[1] = 0;
    for(int i : g[1])
        q.push({i, 1});

    while(!q.empty()){
        auto k = q.front();
        q.pop();
        if(vis[k.V] >= 0) continue;
        vis[k.V] = k.D;
        if(maxD <= k.D){
            if(maxD < k.D) {
                maxV.clear();
                maxD = k.D;
            }
            maxV.push_back(k.V);
        }
        for(int i : g[k.V])
            q.push({i, k.D+1});
    }

    sort(maxV.begin(), maxV.end());
    cout << maxV[0] << " " << vis[maxV[0]] << " " << maxV.size();

    return 0;
}