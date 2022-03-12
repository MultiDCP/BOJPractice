#include <bits/stdc++.h>
using namespace std;
int n, s, result;
int orig[20];

void func(int sum, int k, int count, int cb){
    int isCount = 0;
    if(sum == s && count > 0 && !cb) {
        result++;
        isCount = 1;
    }
    if(k == n) return;
    if(isCount || cb) func(sum, k+1, count, 1);
    else func(sum, k+1, count, 0);
    func(sum+orig[k], k+1, count+1, 0);
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> s;
    for(int i=0; i<n; i++) cin >> orig[i];
    sort(orig, orig+n);
    func(0, 0, 0, 0);
    cout << result;
    return 0;
}

/*
오답 이유
힌트 없었으면 절대 못 풀었을 백트래킹 절망편이자 ㅄ민 수학 능지처참편
말이 백트래킹이지 수학을 얼마나 잘하느냐를 따지는 문제였던 거 같다
비트 마스크 또는 재귀를 이용해서 풀 수 있는 문제인데
중복을 피하는 방법을 내가 제대로 떠올리지를 못했다
비트 마스크의 경우 모든 경우에 부분집합의 유무를 판단해서
그것들을 모두 더해서 비교하면 되는 거였고
재귀의 경우 넣을지 말지를 판단하면서 '끝까지 파고들어서'
결과가 s면 결과값에 1을 더하는 식이었는데
비트 마스크 방식은 내가 아예 쓰지를 못했고
재귀는 가지치기를 한답시고 중간에 쓸데없는 변수를 써서 잘라내려고 했다
근데 어짜피 시간복잡도 상으로 2^20인데 이러면 1초안에 충분히 해서
끝까지 완전탐색을 수행한 다음 결과를 따져도 무방하며 그게 코드가 더 간결하다
어찌됐든 가지치기를 무조건 해야 시간초과가 안 생기는지,
할 필요가 없다면 완전탐색을 해서 굴려도 되는지를 판단하는 문제였던 거 같다
그래서 브루트 포스 알고리즘이 분류로 들어가있던 거 같다
*/