#include <bits/stdc++.h>
using namespace std;
#define P first
#define D second
int n, m, k, x;
vector<int> g[300001];
int dis[300001];
queue<pair<int, int>> q;
vector<int> minV;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> k >> x;
    memset(dis, -1, sizeof(dis));
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
    }

    dis[x] = 0;
    for(int i : g[x])
        q.push({i, 1});
    
    while(!q.empty()){
        auto tmp = q.front();
        q.pop();

        if(dis[tmp.P] >= 0) continue;
        dis[tmp.P] = tmp.D;
        for(int i : g[tmp.P]){
            q.push({i, dis[tmp.P]+1});
        }
    }

    for(int i=1; i<=n; i++){
        if(dis[i] == k)
            minV.push_back(i);
    }

    if(minV.empty())
        cout << -1;
    else{
        for(int i : minV)
            cout << i << "\n";
    }

    return 0;
}