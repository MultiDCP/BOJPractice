#include <bits/stdc++.h>
using namespace std;
int n, m;
string d[101][101];
string BigSum(string a, string b){
    int sum = 0;
    string newString = "";
    while(!a.empty() || !b.empty() || sum != 0){
        if(!a.empty()){
             sum += a.back() - '0';
             a.pop_back();
        }
        if(!b.empty()){
            sum += b.back() - '0';
            b.pop_back();
        }
        newString.push_back(sum % 10 + '0');
        sum /= 10;
    }
    reverse(newString.begin(), newString.end());
    return newString;
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for(int i=1; i<=n; i++){
        d[i][0] = "1";
        d[i][1] = to_string(i);
    }
    for(int i=2; i<=n; i++)
        for(int j=2; j<=m; j++)
            d[i][j] = BigSum(d[i-1][j-1], d[i-1][j]);
    
    cout << d[n][m];

    return 0;
}

/*
외부의 힌트를 받아 풀었음. 복습 필요.

큰 수 연산에 대해 익숙해질 필요가 있긴 하다.
코테에서는 파이썬이라는 치트키가 있기에 나오진 않을테지만
그래도 C++에서 ll을 넘어가는 범위의 입출력과 계산을 알아두는 게 좋을 것이다
*/