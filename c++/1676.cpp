#include <bits/stdc++.h>
using namespace std;
int n, res;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    res += n/5;
    res += n/25;
    res += n/125;
    /*
    while(n >= 5){
        res += n / 5;
        n /= 5;
    }
    */
    cout << res;

    return 0;
}

/*
강의와 함께 진행함. 복습 필요.
2와 5를 소인수로 가져야 0의 개수가 늘어나게 되는 것이므로
5보다 저명하게 더 많은 2는 제쳐두고
5의 개수를 세주면 그것이 곧 0의 개수(정확히는, 인수로 가지고 있는 10의 개수)가 될 것이다.
*/