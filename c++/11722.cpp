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
    
    d[1] = 1;
    res = 1;
    for(int i=2; i<=n; i++){
        d[i] = 1;
        for(int j=1; j<n; j++)
            if(a[j] > a[i])
                d[i] = max(d[i], d[j] + 1);
        
        res = max(res, d[i]);
    }

    cout << res << "\n";

    return 0;
}