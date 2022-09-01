#include <bits/stdc++.h>
using namespace std;
int t, res;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for(int i=0; i<5; i++){
        cin >> t;
        if(t < 40) t = 40;
        res += t;
    }
    cout << res / 5 << "\n";

    return 0;
}