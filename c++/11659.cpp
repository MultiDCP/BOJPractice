#include <bits/stdc++.h>
using namespace std;
int n, m, i, j;
int a[100001];
int d[100001];
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for(int k=1; k<=n; k++)
        cin >> a[k];
    d[1] = a[1];
    for(int k=2; k<=n; k++)
        d[k] = d[k-1] + a[k];
    for(int k=0; k<m; k++){
        cin >> i >> j;
        cout << d[j] - d[i-1] << "\n";
    }

    return 0;
}