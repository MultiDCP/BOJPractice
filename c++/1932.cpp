#include <bits/stdc++.h>
using namespace std;
int n;
int a[501][501];
int d[501][501];
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i=0; i<n; i++)
        for(int j=0; j<=i; j++)
            cin >> a[i][j];
    
    d[0][0] = a[0][0];
    for(int i=1; i<n; i++)
        for(int j=0; j<=i; j++)
            if(j == 0) d[i][j] = a[i][j] + d[i-1][0];
            else if(j == i) d[i][j] = a[i][j] + d[i-1][i-1];
            else d[i][j] = a[i][j] + max(d[i-1][j-1], d[i-1][j]);
    cout << *max_element(d[n-1], d[n-1]+n);
    return 0;
}