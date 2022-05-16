#include <bits/stdc++.h>
using namespace std;
long long a, b;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> a >> b;
    cout << (a * b) / __gcd(a, b);

    return 0;
}