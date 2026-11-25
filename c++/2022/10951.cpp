#include <iostream>
using namespace std;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b;

    while(cin >> a >> b){
        cout << a+b << '\n';
    }

    return 0;
}

/*
풀이 참고한 코드임.
while(cin >> a)를 할 경우
a의 입력이 종료되거나 잘못된 값이 입력될 때까지
while문을 계속 반복할 수 있게 된다.
*/