#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> tr[100001];
int res[100001];
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i=1; i<n; i++){
        int a, b;
        cin >> a >> b;
        tr[a].push_back(b);
        tr[b].push_back(a);
    }

    queue<int> q;
    q.push(1);
    while(!q.empty()){
        int k = q.front();
        q.pop();
        for(int tmp : tr[k]){
            if(res[k] == tmp) continue;
            res[tmp] = k;
            q.push(tmp);
        }
    }

    for(int i=2; i<=n; i++)
        cout << res[i] << "\n";

    return 0;
}