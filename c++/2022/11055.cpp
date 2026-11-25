#include <bits/stdc++.h>
using namespace std;
int n, res;
int a[1001];
int d[1001];
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i=1; i<=n; i++)
        cin >> a[i];

    d[1] = a[1];
    for(int i=2; i<=n; i++){
        int maxS = 0;
        for(int j=1; j<i; j++){
            if(a[j] < a[i])
                maxS = max(maxS, d[j]);
        }
        d[i] = maxS + a[i];
    }

    for(int i=1; i<=n; i++)
        res = max(res, d[i]);
    
    cout << res << "\n";

    return 0;
}