#include <bits/stdc++.h>
using namespace std;
#define INF 1000000009
#define ll long long
int t, n;
ll d[1000001];
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    d[1] = 1;
    d[2] = 2;
    d[3] = 4;
    for(int i=4; i<=1000000; i++){
        d[i] = d[i-1] % INF + d[i-2] % INF + d[i-3] % INF;
        d[i] %= INF;
    }
    for(int i=0; i<t; i++){
        cin >> n;
        cout << d[n] << "\n";
    }

    return 0;
}