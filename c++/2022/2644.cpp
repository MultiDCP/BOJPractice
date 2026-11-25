#include <bits/stdc++.h>
using namespace std;
int n, m, a, b, res;
vector<int> v[101];
int vis[101];
queue<int> q;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> a >> b >> m;
    for(int i=0; i<m; i++){
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    q.push(a);
    while(!q.empty()){
        int k = q.front();
        q.pop();
        for(int i : v[k]){
            if(vis[i] > 0) continue;
            vis[i] = vis[k] + 1;
            if(i == b){
                cout << vis[i] << "\n";
                return 0;
            }
            q.push(i);
        }
    }
    cout << -1 << "\n";

    return 0;
}