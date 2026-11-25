#include <bits/stdc++.h>
using namespace std;
int d[1001][1001];
int n, k;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;
    for(int i=1; i<=n; i++){
        d[i][0] = 1;
        d[i][1] = i;
    }

    for(int i=2; i<=n; i++){
        for(int j=1; j<=k; j++){
            d[i][j] = d[i-1][j] % 10007 + d[i-1][j-1] % 10007;
            d[i][j] %= 10007;
        }
    }

    cout << d[n][k];

    return 0;
}