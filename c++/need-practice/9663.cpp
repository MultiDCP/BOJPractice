#include <bits/stdc++.h>
using namespace std;
int n, result;
int isUsed1[14];
int isUsed2[28];
int isUsed3[28];
void func(int k){
    if(k == n){
        result++;
        return;
    }
    else{
        for(int i=0; i<n; i++){
            if(isUsed1[i] == 1) continue;
            if(isUsed2[i+k] == 1) continue;
            if(isUsed3[i-k+n-1] == 1) continue;
            isUsed1[i] = 1;
            isUsed2[i+k] = 1;
            isUsed3[i-k+n-1] = 1;
            func(k+1);
            isUsed1[i] = 0;
            isUsed2[i+k] = 0;
            isUsed3[i-k+n-1] = 0;
        }
    }
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    func(0);
    cout << result;

    return 0;
}

/*
강의를 따라 힌트를 참고하고 풀었음. 복습 반드시 필요.
왜 isUsed가 3개인지,
그리고 isUsed들의 인덱스가 가리키는 것이 무엇인지를
반드시 이해하고 있어야 한다.
그리고 다른 문제에서도 이런 구조를 떠올리면 된다.
핵심은 이를 수학적으로 풀어내면 답이 나올 수 있다는 것이다.
또한 백트래킹 문제에서는 다음을 상기해둬라.
1. 상태공간의 모양이 어떤 식인가?
2. 어떤 변수가 필요한가?
를 문제 상황에 맞게 정할 것.
*/