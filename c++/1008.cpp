#include <iostream>

using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b;
    cin >> a >> b;

    double c = double(a)/double(b);

    cout << fixed;
    cout.precision(12);
    cout << c << endl;
    return 0;
}

/*
오답횟수가 많았던 이유
1. cout.precision을 사용할 때 cout << fixed를 사용하지 않았었음
2. 오차범위가 10^-9까지 허용이면 double을 써야하나 float이나 long double등을 사용
- 헌데 long double을 사용했을 때 결과는 부정확함. 1번이 주 오답원인이었음.
*/