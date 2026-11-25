#include <bits/stdc++.h>
using namespace std;
int a, t;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    for(int i=0; i<4; i++){
        cin >> a;
        t += a;
    }
    cout << t/60 << "\n" << t%60;
    return 0;
}