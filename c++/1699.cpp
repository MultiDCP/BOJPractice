#include <bits/stdc++.h>
using namespace std;
int n;
int d[100001];
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i=1; i*i<=100000; i++)
        d[i*i] = 1;
    int c = 2;
    for(int i=2; i<=100000; i++)
        if(i < c*c){
            int tmp = c-1;
            d[i] = d[tmp*tmp] + d[i-(tmp*tmp)];
            tmp--;
            while(tmp > 0){
                d[i] = min(d[i], d[tmp*tmp] + d[i-(tmp*tmp)]);
                tmp--;
            }
        }
        else
            c++;
    cout << d[n];

    return 0;
}