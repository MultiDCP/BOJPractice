#include <bits/stdc++.h>
using namespace std;
#define ll long long
int t, n;
ll d[101];
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    d[1] = 1;
    d[2] = 1;
    d[3] = 1;
    d[4] = 2;
    for(int i=5; i<=100; i++)
        d[i] = d[i-1] + d[i-5];
    for(int i=0; i<t; i++){
        cin >> n;
        cout << d[n] << "\n";
    }

    return 0;
}