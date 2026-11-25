#include <bits/stdc++.h>
using namespace std;
#define INF 0x7f7f7f7f
int n, m, st, en;
int a[100000];
int minE = INF;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    for(int i=0; i<n; i++)
        cin >> a[i];
    sort(a, a+n);
    
    while(en < n && st <= n-1){
        while(a[en] - a[st] < m){
            en++;
            if(en >= n) break;
        }
        if(en < n){
            minE = min(minE, a[en] - a[st]);
            st++;
        }
    }
    
    cout << minE;
    
    return 0;
}

/*
강의와 함께 진행함. 복습 필요.
*/