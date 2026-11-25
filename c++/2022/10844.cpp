#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000000
#define ll long long
int n;
ll res;
ll d[101][10];
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    for(int i=1; i<10; i++)
        d[1][i] = 1;
    
    for(int i=2; i<=n; i++)
        for(int j=0; j<10; j++){
            if(j == 0)
                d[i][j] = d[i-1][j+1] % MOD;
            else if(j == 9)
                d[i][j] = d[i-1][j-1] % MOD;
            else
                d[i][j] = d[i-1][j+1] % MOD + d[i-1][j-1] % MOD;
            d[i][j] %= MOD;
        }
    
    for(int i=0; i<10; i++)
        res += (d[n][i] % MOD);
    res %= MOD;
    cout << res;
    
    return 0;
}

/*
오답 이유
1. 수식 실수함
2. 결과값 낼 때... 오버플로우... 생각 못했다....
*/