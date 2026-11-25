#include <bits/stdc++.h>
using namespace std;
int n;
int arr[100001];
int d[100001];
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    int m = -0x7f7f7f7f;
    for(int i=0; i<n; i++){
        cin >> arr[i];
        if(i == 0)
            d[i] = arr[i];
        else
            d[i] = max(0, d[i-1]) + arr[i];
        if(d[i] > m)
            m = d[i];
    }
    cout << m;
    return 0;
}

/*
강의의 힌트를 받아서 풀음. 복습 필요
*/