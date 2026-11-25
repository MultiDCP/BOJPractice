#include <bits/stdc++.h>
using namespace std;
int n, m;
int fib[41];
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> m;
        if(m == 0) cout << "1 0\n";
        else if(m == 1) cout << "0 1\n";
        else{
            fib[0] = 0;
            fib[1] = 1;
            for(int i=2; i<=m; i++)
                fib[i] = fib[i-1] + fib[i-2];
            cout << fib[m-1] << " " << fib[m] << "\n";
            memset(fib, 0, sizeof(fib));
        }
    }
    return 0;
}