#include <bits/stdc++.h>
using namespace std;
int n, m, tmp, res, en;
int a[10000];
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for(int i=0; i<n; i++)
        cin >> a[i];
    
    for(int st=0; st<n; st++){
        while(en < n && tmp < m){
            tmp += a[en];
            en++;
        }
        if(tmp == m)
            res++;
        tmp -= a[st];
    }
    cout << res;

    return 0;
}