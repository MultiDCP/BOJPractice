#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll func(ll a, ll b, ll c){
    if(b == 0) return 1;
    ll tmp = func(a, b/2, c);
    tmp = tmp * tmp % c;
    if(b % 2 == 1)
        return tmp * a % c;
    else
        return tmp % c;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll a, b, c;
    cin >> a >> b >> c;

    cout << func(a, b, c);

    return 0;
}

/*
강의의 힌트를 받음. 복습 필요

오답 정리
일단 base condition을 잘못 설정했다.
b == 0일때까지 쪼개질 수 있음을 간과하지 못했음.

왜 이전 코드에서는 오답이 나고 현 코드에서는 정답이 나오는가?
if(b == 1) return a % c;
ll tmp = func(a, b/2, c);
if(b % 2 == 1)
    return tmp * tmp * a % c;
else
    return tmp * tmp % c;

내가 여기서 실수를 범한 것이
((tmp^2) * a) % c를 하게 되면 tmp^2 % c * a % c가 되는데
이 부분을 안 고치고 내가 그냥 제출을 해버렸다
이 경우 tmp * tmp * a 를 계산할 때 오버플로우가 발생할 수 있다
중간에 맞왜틀된 부분은 애매한데 일단 똑같아서 그랬거니 싶다
어쨌든 이 문제는 재귀인줄 알았더니 알고보니 분할정복 알고리즘이었고
이를 잘 쪼개고 분배법칙을 잘 써서 base condition과 리턴 조건을 잘 짜는 것이
이런 유형의 문제에서 중요할 거 같다
*/