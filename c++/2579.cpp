#include <bits/stdc++.h>
using namespace std;
int n, big;
int a[301];
int d[301][2];
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i=1; i<=n; i++)
        cin >> a[i];
    if(n == 1)
        cout << a[1];
    else{
        d[1][0] = a[1];
        d[1][1] = 0;
        for(int i=2; i<=n; i++){
            d[i][0] = a[i] + max(d[i-2][0], d[i-2][1]);
            d[i][1] = a[i] + d[i-1][0];
            big = max(d[i][0], d[i][1]);
        }
        cout << big;
    }
    
    return 0;
}

/*
힌트를 받아서 풀었음. 복습 반드시 필요
계단 부수고 싶다
굳이 2차원 배열이 아니더라도 그냥 1차원 배열로 풀 수 있었다
max(a[i] + d[i-2], a[i] + a[i-1] + d[i-3])
이게 되는 이유는 i-3에서 i-1을 밟고 i를 밟은 것으로 계산하는 거라
계단을 3번 연속으로 밟을 일이 없다
아무튼 좋은 풀이 및 접근법은 받아들일 수 있도록 하고
여러 방향에서 많이 바라볼 필요가 있을 거 같다
*/