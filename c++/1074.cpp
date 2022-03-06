#include <bits/stdc++.h>
using namespace std;

int func(int n, int r, int c){
    if(n == 1){
        if(r == 0 && c == 0) return 1;
        else if(r == 0 && c == 1) return 2;
        else if(r == 1 && c == 0) return 3;
        else if(r == 1 && c == 1) return 4;
    }
    else{
        int tmp = (int)pow(2, n-1);
        int rem = (int)pow(4, n-1);
        int new_r = r / tmp;
        int new_c = c / tmp;
        if(new_r == 0 && new_c == 0)
            return func(n-1, r%tmp, c%tmp);
        else if(new_r == 0 && new_c == 1)
            return rem + func(n-1, r%tmp, c%tmp);
        else if(new_r == 1 && new_c == 0)
            return rem * 2 + func(n-1, r%tmp, c%tmp);
        else if(new_r == 1 && new_c == 1) return rem * 3 + func(n-1, r%tmp, c%tmp);
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, r, c;
    cin >> n >> r >> c;
    cout << func(n, r, c) - 1 << "\n";
    //result += func(n, r, c);
    //cout << result;

    return 0;
}

/*
보충의견
2^(n-1)의 제곱을 구해서(길이의 절반을 구해서)
이를 필요에 따라 뺀 재귀값과 길이의 절반의 제곱을 일정량 더하면
똑같은 결과값이 나오며 코드도 더 간결해진다.
물론 rem 값을 더해준 게 내 방식도 틀린 건 아니긴 하며
나는 이전 값들은 rem으로 더한다고 생각하고 인덱스를 0~3짜리로 만들어서 계산하긴 했다
잘 나오긴 하나 더 깔끔하게, 귀납적으로 생각하는 훈련을 하는 것이 더 좋을 거 같다
*/