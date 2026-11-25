#include <bits/stdc++.h>
using namespace std;
int d[46];
int k;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> k;
    d[0] = 0;
    d[1] = 1;
    d[2] = 1;
    for(int i=3; i<=k; i++)
        d[i] = d[i-1] + d[i-2];
    if(k == 0)
        cout << "1 0";
    else
        cout << d[k-1] << " " << d[k];

    return 0;
}