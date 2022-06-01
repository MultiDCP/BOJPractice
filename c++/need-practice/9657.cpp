#include <bits/stdc++.h>
using namespace std;
int d[1001];
int n;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    d[1] = 1;
    d[2] = 2;
    d[3] = 1;
    d[4] = 1;
    for(int i=5; i<=n; i++)
        if(max(d[i-1], max(d[i-3], d[i-4])) == 2)
            d[i] = 1;
        else
            d[i] = 2;
    
    if(d[n] == 2)
        cout << "CY";
    else
        cout << "SK";

    return 0;
}

/*
해설의 도움을 받음. 복습 필요.
*/