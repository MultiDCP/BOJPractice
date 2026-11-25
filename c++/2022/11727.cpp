#include <bits/stdc++.h>
using namespace std;
int n;
int d[1001];
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    d[1] = 1;
    d[2] = 3;
    for(int i=3; i<=n; i++){
        d[i] = d[i-1] % 10007 + d[i-2]*2 % 10007;
        d[i] %= 10007;
    }
    cout << d[n];

    return 0;
}

/*
여담
조금 특이한 형태의 피보나치 비슷한 거라고 볼 수 있겠다
이런 타일링 문제에서 점화식 세울 때 주의할 점은
타일을 각각 사용했을 때 나머지 구역을 채울 때의 경우의 수를 고려해야 한다는 것이다
그러니까 타일 1을 놓았을 때 경우의 수,
타일 2를 놓았을 때 경우의 수, 타일 3을 놓았을 때 경우의 수를 따로 계산해서
이것들을 전부 더해주기만 하면 된다는 것
*/