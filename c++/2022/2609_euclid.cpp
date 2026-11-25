#include <bits/stdc++.h>
using namespace std;
int a, b;
int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a%b);
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> a >> b;
    int result = gcd(a, b);
    cout << result << "\n" << a * b / result;

    return 0;
}