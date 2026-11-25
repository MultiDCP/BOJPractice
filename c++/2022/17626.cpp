#include <bits/stdc++.h>
using namespace std;
int d[50001];
int n;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    int tmp = 1;
    while(tmp*tmp <= 50000){
        d[tmp*tmp] = 1;
        tmp++;
    }
    int maxC = 1;
    d[2] = 2;
    for(int i=3; i<=n; i++){
        if(d[i] != 1){
            int tmpC = maxC;
            int minV = 5;
            while((tmpC*tmpC) >= 1){
                minV = min(minV, d[i-(tmpC*tmpC)]);
                tmpC--;
            }
            d[i] = 1 + minV;
        }
        else
            maxC++;
    }
    cout << d[n];

    return 0;
}