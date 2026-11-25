#include <bits/stdc++.h>
using namespace std;
int n, k;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i=1; i<=n; i++)
        k += i;
    cout << k;

    return 0;
}