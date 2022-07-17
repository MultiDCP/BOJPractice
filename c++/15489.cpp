#include <bits/stdc++.h>
using namespace std;
#define ll long long
int r, c, w;
ll d[31][31];
ll res;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> r >> c >> w;
    for(int i=1; i<=r+w; i++){
        d[i][1] = 1;
        d[i][i] = 1;
    }
    for(int i=3; i<=r+w; i++)
        for(int j=2; j<i; j++)
            d[i][j] = d[i-1][j-1] + d[i-1][j];

    for(int i=0; i<w; i++)
        for(int j=0; j<=i; j++)
            res += d[r+i][c+j];
        
    cout << res;
/*
    for(int i=1; i<=r+w; i++){
        for(int j=1; j<=i; j++){
            cout << d[i][j] << " ";
        }
        cout << "\n";
    }
*/
    return 0;
}