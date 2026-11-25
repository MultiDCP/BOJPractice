#include <bits/stdc++.h>
using namespace std;

char arr[2187][2187];
void func(int n, int x, int y){
    if(n == 1) return;
    if(x == 1 && y == 1){
        for(int i=n/3; i<2*n/3; i++)
            for(int j=n/3; j<2*n/3; j++)
                arr[i][j] = ' ';
    }
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++){
            if(i % (i / 3) == 1 || j % (j / 3) == 1)
                func(n/3, i%3, j%3);
        }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            arr[i][j] = '*';
        }
    }

    func(n, 1, 1);

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)
            cout << arr[i][j];
        cout << "\n";
    }

    return 0;
}

/*
오답정리
재귀 + 분할정복
기본적인 단위에서 규칙을 만족시키기 위한 조건은
i%3 == 1 && j%3 == 1이다.
(1,1),(1,4),(1,7),...
일단 풀이 자체는 출력을 실시간으로 하나하나 하는 거다.
공백을 채워넣으려 했던 내 풀이가 틀린 거라고 봐도 됨.
N = 9일 경우, 비어있는 가운데 좌표는
(3,3),(3,4),(3,5),(4,3),(4,4)...(5,5)이다.
수식으로 표현하면 3*3의 기본단위 모형이 한 개 나오고 비어있다는 표현
따라서 (i/3) % 3 == 1 && (j/3) % 3 == 1의 조건을 맞추면 된다.
이를 치환하면
(i / (n/3)) % 3 == 1 && (j / (j/3)) % 3 == 1 이 될 거임.
이 조건을 재귀로 만들면 된다.
*/