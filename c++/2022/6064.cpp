#include <bits/stdc++.h>
using namespace std;
int t;
int mod(int m, int n, int x, int y){
    if(x == m) x = 0;
    if(y == n) y = 0;
    for(int i=x; i<=m*n/__gcd(m, n); i=i+m){
        if(i == 0) continue;
        if(i % m == x && i % n == y) return i;
    }
    return -1;
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    for(int i=0; i<t; i++){
        int m, n, x, y;
        cin >> m >> n >> x >> y;
        cout << mod(m, n, x, y) << "\n";
    }
    return 0;
}

/*
강의와 함께 진행함. 복습 필요.
*/