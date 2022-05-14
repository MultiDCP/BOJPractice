#include <bits/stdc++.h>
using namespace std;
int n;
int a[100000];
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i=0; i<n; i++)
        cin >> a[i];
    sort(a, a+n);
    cout << a[0] << " ";
    for(int i=1; i<n; i++)
        if(a[i] != a[i-1])
            cout << a[i] << " ";

    return 0;
}