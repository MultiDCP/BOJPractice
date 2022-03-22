#include <bits/stdc++.h>
using namespace std;
int n;
int d[5001];
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i=0; i<=n; i++)
        d[i] = 0x7f7f7f7f;
    d[3] = 1;
    d[5] = 1;
    for(int i=6; i<=n; i++)
        if(i % 5 == 0) d[i] = i/5;
        else{
            int tmp = min(d[i-3], d[i-5]);
            if(tmp != 0x7f7f7f7f)
                d[i] = tmp + 1;
        }
    if(d[n] == 0x7f7f7f7f)
        cout << -1;
    else
        cout << d[n];
    return 0;
}