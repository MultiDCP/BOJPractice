#include <bits/stdc++.h>
using namespace std;
int n;
int fac(int i){
    if(i <= 0) return 1;
    return i * fac(i-1);
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    cout << fac(n);

    return 0;
}