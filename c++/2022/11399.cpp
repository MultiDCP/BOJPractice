#include <bits/stdc++.h>
using namespace std;
int n, res;
int a[1000];
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i=0; i<n; i++)
        cin >> a[i];
    
    sort(a, a+n);

    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++)
            res += a[j];
        res += a[i];
    }

    cout << res << "\n";

    return 0;
}