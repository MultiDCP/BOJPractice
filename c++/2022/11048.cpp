#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[1001][1001];
int d[1001][1001];
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            cin >> a[i][j];
    
    d[1][1] = a[1][1];

    for(int i=2; i<=m; i++)
        d[1][i] = a[1][i] + d[1][i-1];
    for(int i=2; i<=n; i++)
        d[i][1] = a[i][1] + d[i-1][1];

    for(int i=2; i<=n; i++){
        for(int j=2; j<=m; j++){
            d[i][j] = a[i][j] + max(d[i-1][j], d[i][j-1]);
        }
    }

    cout << d[n][m] << "\n";

    return 0;
}