#include <bits/stdc++.h>
using namespace std;
int n;
int d[1000001];
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    d[1] = 1;
    d[2] = 2;
    for(int i=3; i<=n; i++){
        d[i] = d[i-1] % 15746 + d[i-2] % 15746;
        d[i] %= 15746;
    }
    cout << d[n];

    return 0;
}