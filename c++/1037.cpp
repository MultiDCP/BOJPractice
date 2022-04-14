#include <bits/stdc++.h>
using namespace std;
int n;
int a[50];
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i=0; i<n; i++)
        cin >> a[i];
    sort(a, a+n);
    if(n % 2 == 1)
        cout << a[n/2] * a[n/2];
    else
        cout << a[0] * a[n-1];

    return 0;
}