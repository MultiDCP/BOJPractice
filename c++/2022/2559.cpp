#include <bits/stdc++.h>
using namespace std;
int n, k, maxS;
int a[100001];
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;
    for(int i=0; i<n; i++)
        cin >> a[i];
    int tmp = 0;
    for(int i=0; i<k; i++)
        tmp += a[i];
    maxS = tmp;
    for(int i=k; i<n; i++){
        tmp += a[i];
        tmp -= a[i-k];
        maxS = max(tmp, maxS);
    }
    cout << maxS;

    return 0;
}