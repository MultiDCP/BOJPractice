#include <bits/stdc++.h>
using namespace std;
int n, k;
int a[100];
int d1[10001];
int d2[10001];
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;
    for(int i=0; i<n; i++)
        cin >> a[i];
    sort(a, a+n);

    for(int i=0; i<k; i++)
        d1[i] = 1;

    for(int i=0; i<n; i++){
        for(int j=a[i]; j<k; j++){
            d2[j] = d1[j] + d2[j-a[i]];
        }
        for(int i=0; i<n; i++){
            d1[i] = d2[i];
        }
    }
    cout << d2[k];

    return 0;
}

/*
대체 어떤 매커니즘인지 이해가 안 간다
정답 코드의 흐름을 이해하기가 어려움
*/