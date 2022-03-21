#include <bits/stdc++.h>
using namespace std;

int n;
int minV = 0x7f7f7f7f;
void bag(int n, int cur){
    if(n < 3)
        if(n == 0)
            minV = min(minV, cur);
        else
            return;
    else if(n % 5 == 0) minV = min(minV, cur + n/5);
    else if(n % 3 == 0) {
        bag(n-3, cur+1);
        minV = min(minV, cur + n/3);
    }
    else{
        bag(n-5, cur+1);
        bag(n-3, cur+1);
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    bag(n, 0);
    if(minV == 0x7f7f7f7f) cout << -1;
    else cout << minV;

    return 0;
}

/*
DP 및 그리디를 사용하지 않은 재귀식 풀이.
추후 그리디를 활용해 풀어볼 것
*/