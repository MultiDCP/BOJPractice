#include <bits/stdc++.h>
using namespace std;
int m, n;
vector<bool> e(10001);
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> m >> n;
    fill(e.begin(), e.end(), true);
    e[1] = false;
    for(int i=2; i*i<=10000; i++){
        if(!e[i]) continue;
        for(int j=i*i; j<=10000; j=j+i)
            if(e[j] == true) e[j] = false;
    }

    int res = 0;
    int min = 0x7f7f7f7f;
    for(int i=m; i<=n; i++)
        if(e[i] == true){
            if(i < min)
                min = i;
            res += i;
        }

    if(res == 0) cout << -1;
    else cout << res << "\n" << min;

    return 0;
}