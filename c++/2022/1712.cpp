#include <bits/stdc++.h>
using namespace std;
int a, b, c;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> a >> b >> c;
    if(c-b == 0 || a/(c-b) < 0) cout << -1;
    else cout << a/(c-b)+1;

    return 0;
}