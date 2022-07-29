#include <bits/stdc++.h>
using namespace std;
int n;
long long d[81];
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    d[1] = 1;
    d[2] = 1;
    for(int i=3; i<=n; i++)
        d[i] = d[i-1] + d[i-2];
    
    cout << d[n] * 4 + d[n-1] * 2 << "\n";

    return 0;
}