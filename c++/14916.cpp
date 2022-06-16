#include <bits/stdc++.h>
using namespace std;
int d[100001];
int n;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    memset(d, -1, sizeof(d));
    d[2] = 1;
    d[4] = 2;
    d[5] = 1;
    for(int i=6; i<=n; i++){
        if(d[i-2] == -1 && d[i-5] == -1) d[i] = -1;
        else{
            if(d[i-2] == -1) d[i] = 1 + d[i-5];
            else if(d[i-5] == -1) d[i] = 1 + d[i-2];
            else d[i] = min(1 + d[i-2], 1 + d[i-5]);
        }
    }
    cout << d[n];

    return 0;
}