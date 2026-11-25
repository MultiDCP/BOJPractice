#include <bits/stdc++.h>
using namespace std;
int n, m, r;
vector<int> v[100001];
stack<int> s;
int vis[100001];
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> r;
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i=1; i<n; i++)
        sort(v[i].begin(), v[i].end());

    s.push(r);
    int vCnt = 1;
    while(!s.empty()){
        int k = s.top();
        s.pop();
        if(vis[k] > 0) continue;
        vis[k] = vCnt++;
        for(int i : v[k])
            s.push(i);
    }

    for(int i=1; i<=n; i++)
        cout << vis[i] << "\n";

    return 0;
}