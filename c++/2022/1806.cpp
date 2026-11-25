#include <bits/stdc++.h>
using namespace std;
#define INF 0x7f7f7f7f
int n, s;
int a[100000];
int minL = INF;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> s;
    for(int i=0; i<n; i++)
        cin >> a[i];

    int en = 0;
    int tmp = 0;
    for(int st=0; st<n; st++){
        while(en < n && tmp < s){
            tmp += a[en];
            en++;
        }
        if(en >= n) {
            if(tmp >= s) minL = min(minL, en - st);
            tmp -= a[st];
            continue;
        }
        minL = min(minL, en - st);
        tmp -= a[st];
    }
    if(minL == INF) cout << 0;
    else cout << minL;

    return 0;
}