#include <bits/stdc++.h>
using namespace std;
int arr[20000001];
int n, m, tmp;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i=0; i<n; i++){
        cin >> tmp;
        arr[tmp+10000000]++;
    }
    cin >> m;
    for(int i=0; i<m; i++){
        cin >> tmp;
        cout << arr[tmp+10000000] << " ";
    }

    return 0;
}

/*
메모리가 여유가 넘치길래 계수정렬로 맞혔더니 이분탐색 문제라고?
일단 확인...은 했다만 사실 메모리도 많이 주고 그래서
내가 생각할 수 있는 최대로 빠른 방법이 Counting sort였다
이분탐색을 제대로 배우고 나면 그 방법대로 또 풀어보긴 해야겠다
*/