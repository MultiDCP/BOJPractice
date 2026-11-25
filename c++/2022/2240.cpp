#include <bits/stdc++.h>
using namespace std;
int t, w, res;
short a[1001];
int d[1001][31];
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t >> w;
    for(int i=1; i<=t; i++)
        cin >> a[i];
    
    if(a[1] == 1){
        d[1][0] = 1;
        d[1][1] = 0;
    }
    else{
        d[1][0] = 0;
        d[1][1] = 1;
    }

    for(int i=2; i<=t; i++){
        if(a[i] == 1){ // 1번에서 떨어질 경우(j가 짝수일 경우 증가)
            for(int j=0; j<=w; j++){
                if(j > i) continue;
                if(j % 2 == 0)
                    if(j == 0) d[i][j] = d[i-1][j] + 1;
                    else d[i][j] = max(d[i-1][j] + 1, d[i-1][j-1] + 1);
                else d[i][j] = max(d[i-1][j], d[i-1][j-1]);
            }
        }
        else{ // 2번에서 떨어질 경우(j가 홀수일 경우 증가)
            for(int j=0; j<=w; j++){
                if(j > i) continue;
                if(j % 2 == 1)
                    d[i][j] = max(d[i-1][j] + 1, d[i-1][j-1] + 1);
                else 
                    if(j == 0) d[i][j] = d[i-1][j];
                    else d[i][j] = max(d[i-1][j], d[i-1][j-1]);
            }
        }
    }
    /*
    for(int i=1; i<=t; i++){
        for(int j=0; j<=w; j++){
            cout << d[i][j] << " ";
        }
        cout << "\n";
    }*/

    for(int i=0; i<=w; i++)
        res = max(res, d[t][i]);
    cout << res;

    return 0;
}

/*
오답 이유
j == 0일 때 경우를 예외처리할 때
j가 홀수일 때 j % 2를 때리는 경우에서 j == 0인 경우를 제대로 걸러주지 못했다.
*/