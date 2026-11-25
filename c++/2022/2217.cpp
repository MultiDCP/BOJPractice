#include <bits/stdc++.h>
using namespace std;
int n;
int w[100000];
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> w[i];
    sort(w, w+n);
    
    int maxW = -0x7f7f7f7f;
    
    for(int i=1; i<=n; i++)
        maxW = max(w[n-i] * i, maxW);
    cout << maxW;
    return 0;
}

/*
강의의 힌트를 받아 푼 문제임. 복습 필요
*/