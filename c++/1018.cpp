#include <bits/stdc++.h>
using namespace std;

char a[50][50];
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            cin >> a[i][j];
        }
    }

    char white[8][8] =
        {{'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
         {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
         {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
         {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
         {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
         {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
         {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
         {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'}};

    char black[8][8] =
        {{'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
         {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
         {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
         {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
         {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
         {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
         {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
         {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'}};
    
    vector<int> count;
    int temp = 0;

    for(int i=0; i<n-7; i++){
        for(int j=0; j<m-7; j++){ // 유의미한 값만 있는 보드판 분리
            int tempWhite = 0;
            int tempBlack = 0;
            for(int k=0; k<8; k++){
                for(int l=0; l<8; l++){
                    if(a[k+i][l+j] != white[k][l]){
                        tempWhite++;
                    }
                }
            }
            for(int k=0; k<8; k++){
                for(int l=0; l<8; l++){
                    if(a[k+i][l+j] != black[k][l]){
                        tempBlack++;
                    }
                }
            }
            if(tempBlack > tempWhite)
                temp = tempWhite;
            else
                temp = tempBlack;
            count.push_back(temp);
            temp = 0;
        }
    }

    int min = 1000000;

    for(int i=0; i<count.size(); i++){
        if(count[i] < min)
            min = count[i];
    }

    cout << min << '\n';

    return 0;
}

/*
오답 이유
1. 모든 테스트케이스를 실험해보지 않음
또 여기서 실수했다. 귀찮다고 무시하지 말고 전부 넣어보고 판단하자.
2. 경우를 너무 나누고 세밀하게 계산하려고 했음
어짜피 브루트 포스 문제면 시간이나 메모리나 다 넉넉하다.
그냥 무지성으로 원본 2개하고 다 비교해서
칠해야 하는 게 더 작게 나오는 쪽을 고르면 되는데
이걸 또 나누고 저걸 또 나누고 하다가
내가 보지 못한 극히 일부 테스트 케이스에서 오답이 나왔다.
너무 복잡하게 생각하지 말고 그냥 원본 가정하고 기계처럼 다 때려박아보자.
*/