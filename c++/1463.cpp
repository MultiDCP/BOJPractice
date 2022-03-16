#include <bits/stdc++.h>
using namespace std;
int n;
int a[1000001];
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i=2; i<=n; i++){
        a[i] = a[i-1] + 1;
        if(i % 2 == 0)
            a[i] = min(a[i], a[i/2] + 1);
        if(i % 3 == 0)
            a[i] = min(a[i], a[i/3] + 1);
    }
    cout << a[n];
    
    return 0;
}

/* 이전 코드
a[1] = 0;
for(int i=2; i<=n; i++){
    vector<int> v;
    v.push_back(a[i-1] + 1);
    if(i % 2 == 0) v.push_back(a[i/2] + 1);
    if(i % 3 == 0) v.push_back(a[i/3] + 1);
    a[i] = *min_element(v.begin(), v.end());
}
*/

/*
강의와 함께 진행함. 복습 반드시 필요

vector를 안 쓰고 진행할 방법?
a[i]를 먼저 a[i-1] + 1로 놓은 다음
i % 2 == 0 이면 a[i]를 a[i/2]+1과 비교한다
그러고 또 i%3 == 0이면 그 결과를 a[i] == a[i/3]+1과 비교한다

이런 식으로 DP는 최솟값을 배열에 넣고
점화식을 통해서 다음 결과를 미리 쌓아가는 과정이다
n이 100만쯤 되더라도 계산 속도는 내 생각보다 훨씬 빠르기 때문에
(특히 이 VS Code에서 보여지는 것보다 훨씬)
안심하고 for문을 돌려서 O(N)의 코드를 만드는 것이 좋다

vector에 insert를 하고 비교를 하는 과정에서
상당히 많은 시간이 낭비가 된다
이런 점에서 시간을 낭비하지 않도록 유의하자
0.15초 제한에 0.084초가 걸린 건 상당히 아슬아슬했다
*/