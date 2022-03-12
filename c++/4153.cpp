#include <bits/stdc++.h>
using namespace std;

long long a[3];
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while(true){
        for(int i=0; i<3; i++) cin >> a[i];
        long long max = *max_element(a, a+3);
        if(max == 0) break;
        long long tmp = 0;
        for(int i=0; i<3; i++){
            if(a[i] == max) continue;
            tmp += a[i] * a[i];
        }
        if(max * max == tmp) cout << "right\n";
        else cout << "wrong\n";
    }
    return 0;
}