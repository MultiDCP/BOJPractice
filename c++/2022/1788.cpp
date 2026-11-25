#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000
#define MIL 1000000
int d[2000001];
int n;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    d[1+MIL] = 1;
    d[MIL] = 0;
    if(n >= 1){
        for(int i=2; i<=n; i++){
            d[i+MIL] = d[i-1+MIL] % INF + d[i-2+MIL] % INF;
            d[i+MIL] %= INF;
        }
    }
    else if(n < 0){
        for(int i=-1; i>=n; i--){
            d[i+MIL] = d[i+2+MIL] % INF - d[i+1+MIL] % INF;
            d[i+MIL] %= INF;
        }
    }

    if(d[n+MIL] > 0)
        cout << "1\n";
    else if(d[n+MIL] < 0)
        cout << "-1\n";
    else
        cout << "0\n";
    cout << int(abs(d[n+MIL]));

    return 0;
}