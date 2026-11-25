#include <iostream>
#include <ctime>
#include <string>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    int i = 1;
    string str = "";

    cin >> n;

    while(i <= n){
        str += to_string(i++) + '\n';
    }

    cout << str;

    return 0;
}

/*
오답 이유
1. sync_with_stdio를 끄지 않음
이거가 엄청난 차이를 만들어낸다..
2. cin.tie(NULL)을 쓰지 않음
1번과 마찬가지
3. endl을 씀
'\n'과 endl의 차이는 크다.
endl을 쓰는 건 그 때 그 때 버퍼를 비우는 행위라
생각보다 엄청난 시간이 소모됨.
*/