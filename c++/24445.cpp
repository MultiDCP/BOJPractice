#include <bits/stdc++.h>
using namespace std;
int n, m, r;
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
    for(int i=1; i<=n; i++){
        sort(g[i].begin(), g[i].end());
        reverse(g[i].begin(), g[i].end());
    }

    int res = 1;
    vis[r] = 1;
    for(int i : g[r])
        q.push(i);
    
    while(!q.empty()){
        int k = q.front();
        q.pop();
        if(vis[k] > 0) continue;

        vis[k] = ++res;
        for(int i : g[k])
            q.push(i);
    }

    for(int i=1; i<=n; i++)
        cout << vis[i] << "\n";

    return 0;
}