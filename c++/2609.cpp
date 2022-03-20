#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    cout << __gcd(n, m) << "\n" << n * m / __gcd(n, m);

    return 0;
}