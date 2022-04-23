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
        if(a[i] == 1){ // 1������ ������ ���(j�� ¦���� ��� ����)
            for(int j=0; j<=w; j++){
                if(j > i) continue;
                if(j % 2 == 0)
                    if(j == 0) d[i][j] = d[i-1][j] + 1;
                    else d[i][j] = max(d[i-1][j] + 1, d[i-1][j-1] + 1);
                else d[i][j] = max(d[i-1][j], d[i-1][j-1]);
            }
        }
        else{ // 2������ ������ ���(j�� Ȧ���� ��� ����)
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
���� ����
j == 0�� �� ��츦 ����ó���� ��
j�� Ȧ���� �� j % 2�� ������ ��쿡�� j == 0�� ��츦 ����� �ɷ����� ���ߴ�.
*/