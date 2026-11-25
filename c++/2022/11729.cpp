#include <bits/stdc++.h>
using namespace std;

int hanoi(int n, int from, int to, int mid){
    if(n == 1) {
        //cout << from << " " << to << "\n";
        return 1;
    }
    return hanoi(n-1, from, mid, to) + hanoi(1, from, to, mid) + hanoi(n-1, mid, to, from);
}

void hanoi_print(int n, int from, int to, int mid){
    if(n == 1) {
        cout << from << " " << to << "\n";
        return;
    }
    hanoi_print(n-1, from, mid, to);
    cout << from << " " << to << "\n";
    hanoi_print(n-1, mid, to, from);
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int result = 0;
    int n;
    cin >> n;
    result = hanoi(n, 1, 3, 2);
    cout << result << "\n";
    hanoi_print(n, 1, 3, 2);

    return 0;
}

/*
복습 필요
쌍욕을 적고 싶지만 차마 그러지는 못하는 뭐같은 재귀
오답 원인은 단순히 결과값과 이동순서 출력이 뒤집어져서 틀린 거다
사실상 틀린 게 아닌 문제
물론 발상을 바로 떠올린 건 아니다
힌트를 얻기 전까진 중간값을 이용해야하는 것을 까먹고 있었음
헌데 모범답은 그냥 간단히 점화식 써서 결과 올렸더라?
필요할 때는 꼼수를 써야할 때도 있다는 것을 깨달았다
모범답안은 점화식으로 2^n-1 출력하고 그 다음 void로 하노이를 굴렸다
진짜 이건 ㅆㅂ 너무한 거 아니냐고 난 정석대로 int값 받아가면서 풀었는데
*/