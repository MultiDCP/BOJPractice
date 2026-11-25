#include <bits/stdc++.h>
using namespace std;
int a, b;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> a >> b;
    cout << a * (b % 10) << "\n";
    cout << a * (b % 100 - b % 10) / 10 << "\n";
    cout << a * (b - b % 100) / 100 << "\n";
    cout << a * b;

    return 0;
}