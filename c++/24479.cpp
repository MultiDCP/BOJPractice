#include <bits/stdc++.h>
using namespace std;
int n, m, r, cnt;
vector<int> g[100001];
int vis[100001];
stack<int> s;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> r;
    for(int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i=1; i<=n; i++){
        sort(g[i].begin(), g[i].end());
        reverse(g[i].begin(), g[i].end());
    }

    vis[r] = 1;
    cnt = 1;
    for(int i : g[r])
        s.push(i);
    
    while(!s.empty()){
        int k = s.top();
        s.pop();
        if(vis[k] > 0) continue;
        vis[k] = ++cnt;
        for(int i : g[k])
            s.push(i);
    }

    for(int i=1; i<=n; i++)
        cout << vis[i] << "\n";

    return 0;
}