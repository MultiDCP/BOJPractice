#include <bits/stdc++.h>
using namespace std;
int t, h, w, n;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    for(int i=0; i<t; i++){
        cin >> h >> w >> n;
        int res = 1;
        
        while(n > 0){
            while(n > h){
                res++;
                n -= h;
            }
            res += (100 * n);
            n = 0;
        }
        cout << res << "\n";
    }

    return 0;
}