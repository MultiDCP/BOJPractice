#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long a, b;
    cin >> a >> b;

    if(a > b){
        cout << a - b - 1 << "\n";
        for(long long i=b+1; i<a; ++i){
            cout << i << " ";
        }
    }
    else if(a == b){
        cout << "0\n";
    }
    else{
        cout << b - a - 1 << "\n";
        for(long long i=a+1; i<b; ++i){
            cout << i << " ";
        }
    }

    return 0;
}

/*
오답 이유
두 수가 같을 경우를 고려하지 못했다.
두 수가 같을 경우에 a - b - 1은 -1이 됨
근데 이 경우는 틀린 경우
*/