#include <bits/stdc++.h>
using namespace std;
static int w[26] = {3, 2, 1, 2, 3, 3, 2, 3, 3, 2, 
                    2, 1, 2, 2, 1, 2, 2, 2, 1, 2,
                    1, 1, 1, 2, 2, 1};
int d[4001][4001];
string a, b;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> a >> b;
    int lnt = a.length() + b.length();
    for(int i=0; i<lnt; i++)
        if(i % 2 == 0)
            d[0][i] = w[a[i/2] - 'A'];
        else
            d[0][i] = w[b[i/2] - 'A'];
    
    for(int i=1; i<=lnt-2; i++)
        for(int j=1; j<=lnt-i; j++)
            d[i][j-1] = (d[i-1][j-1] + d[i-1][j]) % 10;
            
    cout << d[lnt-2][0] << d[lnt-2][1];

    return 0;
}