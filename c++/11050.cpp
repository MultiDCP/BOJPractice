#include <bits/stdc++.h>
using namespace std;
int n, k;
int fac(int a){
    int res = 1;
    while(a > 0)
        res *= a--;
    return res;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;
    cout << fac(n) / (fac(n - k) * fac(k));

    return 0;
}