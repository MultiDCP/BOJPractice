#include <bits/stdc++.h>
using namespace std;
int n, m, maxC;
vector<int> res;
vector<int> g[10001];
int vis[10001];
queue<int> q;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        g[b].push_back(a);
    }

    for(int i=1; i<=n; i++){
        memset(vis, 0, sizeof(vis));
        int tmpC = 1;
        vis[i] = 1;
        for(int j : g[i])
            q.push(j);
        
        while(!q.empty()){
            int k = q.front();
            q.pop();
            if(vis[k] > 0) continue;
            tmpC++;
            if(maxC <= tmpC){
                if(maxC < tmpC){
                    res.clear();
                    maxC = tmpC;
                }
                res.push_back(i);
            }
            vis[k] = 1;
            for(int j : g[k])
                q.push(j);
        }
    }

    sort(res.begin(), res.end());
    for(int i : res)
        cout << i << " ";

    return 0;
}