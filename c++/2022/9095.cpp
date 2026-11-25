#include <bits/stdc++.h>
using namespace std;
int t, n;
int d[12];
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    d[1] = 1;
    d[2] = 2;
    d[3] = 4;
    for(int i=4; i<=11; i++)
        d[i] = d[i-1] + d[i-2] + d[i-3];
    for(int i=0; i<t; i++){
        cin >> n;
        cout << d[n] << "\n";
    }

    return 0;
}