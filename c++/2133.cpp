#include <bits/stdc++.h>
using namespace std;
int n;
int d[31];
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    d[0] = 0;
    d[2] = 3;
    for(int i=4; i<=n; i+=2){
        d[i] += d[i-2] * 3; // d[i-2]와 d[2]를 합친 경우를 계산함
        for(int j=i-4; j>0; j-=2)
            d[i] += d[j] * 2; // d[i-4], d[i-6], ...과 남은 영역의 고유 경우의 수 2개를 합친 경우를 계산함
        d[i] += 2; // i에서 가질 수 있는 고유 경우의 수 2개를 더해줌
    }
    cout << d[n];

    return 0;
}

/*
뭐 이딴 문제가 다 있어
*/