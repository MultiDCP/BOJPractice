#include <bits/stdc++.h>
using namespace std;
int n;
long long t[36];
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    t[0] = 1;
    t[1] = 1;
    for(int i=2; i<=n; i++)
        for(int j=0; j<i; j++)
            t[i] += t[j] * t[i-1-j];

    cout << t[n];

    return 0;
}