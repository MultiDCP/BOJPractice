#include <bits/stdc++.h>
using namespace std;
int n;
int a[10000];
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i=0; i<n; i++){
        int tmp;
        cin >> tmp;
        a[tmp-1]++;
    }
    for(int i=0; i<10000; i++)
        for(int j=0; j<a[i]; j++)
            cout << i+1 << "\n";
    
    return 0;
}

/*
오답 이유
1. N이 터무니없이 큰데 메모리는 콩알만하게 주고
시간은 넉넉하다 == Counting Sort를 써라
2. 메모리 아낀답시고 무지성으로 short 박지 말고
배열 안에 최악의 경우가 들어갔을 때
오버플로우 없이 전부 수용할 수 있는지를 판단해라
*/