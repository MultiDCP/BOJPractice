#include <bits/stdc++.h>
using namespace std;
#define INF 1000000007
int n;
int d[51];
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    d[0] = 1;
    d[1] = 1;
    d[2] = 3;

    for(int i=3; i<=n; i++){
        d[i] = 1 + d[i-1] % INF + d[i-2] % INF;
        d[i] %= INF;
    }
    cout << d[n];

    return 0;
}