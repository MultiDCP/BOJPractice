#include <bits/stdc++.h>
using namespace std;
#define ll long long
int t, n, m;
ll d[30][30];
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;

    for(int i=1; i<=29; i++){
        d[i][0] = 1;
        d[i][1] = i;
    }
    for(int i=2; i<=29; i++){
        for(int j=2; j<=i; j++){
            d[i][j] = d[i-1][j-1] + d[i-1][j];
        }
    }

    for(int i=0; i<t; i++){
        cin >> n >> m;
        cout << d[m][n] << "\n";
    }

    return 0;
}
