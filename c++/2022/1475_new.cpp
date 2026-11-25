#include <bits/stdc++.h>
using namespace std;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int a[10] = {0, };
    
    int s;
    cin >> s;

    while(s != 0){
        ++a[s % 10];
        s /= 10;
    }

    int maxVar = -1;
    for(int i=0; i<10; i++){
        if(i == 6 || i == 9)
            continue;
        else
            maxVar = max(maxVar, a[i]);
    }

    maxVar = max(maxVar, (a[6] + a[9]) / 2 + (a[6] + a[9]) % 2);

    cout << maxVar << '\n';

    return 0;
}

/*
타인의 풀이를 참고한 코드.
이렇게까지 단축할수도 있음을 볼 수 있다.
분발하자...
*/