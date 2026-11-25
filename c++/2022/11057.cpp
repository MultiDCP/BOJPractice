#include <bits/stdc++.h>
using namespace std;
#define REM 10007
int n, res;
int d[1001][10];
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i=0; i<=9; i++)
        d[1][i] = 1;

    for(int i=2; i<=n; i++){
        for(int j=0; j<=9; j++){
            for(int k=j; k<=9; k++)
                d[i][j] += (d[i-1][k] % REM);
            d[i][j] %= REM;
        }
    }

    for(int i=0; i<=9; i++)
        res += d[n][i];
    
    res %= REM;
    cout << res;

    return 0;
}