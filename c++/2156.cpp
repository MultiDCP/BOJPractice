#include <bits/stdc++.h>
using namespace std;
int n;
int a[10001];
int d[10001][2];
int maxE = 0;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i=1; i<=n; i++)
        cin >> a[i];
    d[1][0] = a[1];
    d[1][1] = a[1];
    d[2][0] = a[2];
    d[2][1] = d[1][0] + a[2];
    maxE = max(d[2][0], d[2][1]);

    for(int i=3; i<=n; i++){
        d[i][0] = max(max(d[i-2][1] + a[i], d[i-2][0] + a[i]), 
                      max(d[i-3][1] + a[i], d[i-3][0] + a[i]));
        maxE = max(d[i][0], maxE);
        d[i][1] = d[i-1][0] + a[i];
        maxE = max(d[i][1], maxE);
    }
    cout << maxE;

    return 0;
}

/*
오답 이유
1. 로직에서 실수를 했다. 무조건 연속으로 뭔가를 마실 필요는 없으며
두 칸 이상 건너뛰고 더 큰 이득을 노려도 되는 로직이 숨어있었다.

2. d[2]를 계산하는 과정에서 최댓값을 저장하는 걸 까먹었다....
*/