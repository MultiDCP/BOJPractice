#include <bits/stdc++.h>
using namespace std;
int t, a, b;
int gcd(int a, int b){
    while(b > 0){
        int tmp = a%b;
        a = b;
        b = tmp;
    }
    return a;
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    for(int i=0; i<t; i++){
        cin >> a >> b;
        cout << (a * b) / gcd(a, b) << "\n";
    }

    return 0;
}