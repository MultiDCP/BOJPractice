#include <bits/stdc++.h>
using namespace std;
int a, b, c;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> a >> b >> c;
    cout << (a+b)%c << "\n";
    cout << ((a%c) + (b%c))%c << "\n";
    cout << (a*b)%c << "\n";
    cout << ((a%c) * (b%c))%c;

    return 0;
}