#include <bits/stdc++.h>
using namespace std;
int n, res;
int a[51];
int b[51];
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for(int i=0; i<n; i++)
        cin >> a[i];
    for(int i=0; i<n; i++)
        cin >> b[i];
    
    sort(a, a+n);
    sort(b, b+n);

    for(int i=0; i<n; i++)
        res += a[i] * b[n-1-i];
    
    cout << res;

    return 0;
}

/*
이럴 거면 대체 왜 b를 가만두라는 조건을 걸어둔겨...?
*/