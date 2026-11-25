#include <bits/stdc++.h>
using namespace std;
int n, k;
int a[10];
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;
    int result = 0;
    for(int i=0; i<n; i++)
        cin >> a[i];
    for(int i=n-1; i>=0; i--){
        if(k < a[i]) continue;
        result += k / a[i];
        k = k % a[i];
    }
    cout << result;

    return 0;
}