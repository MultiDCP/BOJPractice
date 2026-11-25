#include <bits/stdc++.h>
using namespace std;
int i;
int fac(int n){
    if(n == 0) return 0;
    if(n == 1) return 1;
    return fac(n-1) + fac(n-2);
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> i;
    cout << fac(i);    

    return 0;
}