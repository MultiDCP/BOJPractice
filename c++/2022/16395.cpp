#include <bits/stdc++.h>
using namespace std;
int d[31][31];
int n, k;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;
    for(int i=1; i<=n; i++){
        d[i][1] = 1;
        d[i][i] = 1;
    }
    for(int i=2; i<=n; i++)
        for(int j=2; j<=i-1; j++)
            d[i][j] = d[i-1][j] + d[i-1][j-1];
    cout << d[n][k];

    return 0;
}