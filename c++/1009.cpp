#include <bits/stdc++.h>
using namespace std;
int n;
int a, b;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    
    for(int i=0; i<n; i++){
        cin >> a >> b;
        int tmp = 1;
        for(int j=0; j<b; j++){
            tmp *= a;
            tmp %= 10;
        }
        if(tmp == 0)
            cout << 10 << "\n";
        else
            cout << tmp << "\n";
    }
    return 0;
}