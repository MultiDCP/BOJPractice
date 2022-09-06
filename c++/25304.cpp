#include <bits/stdc++.h>
using namespace std;
int x, n, a, b, res;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> x >> n;
    for(int i=0; i<n; i++){
        cin >> a >> b;
        res += a * b;
    }
    if(res == x)
        cout << "Yes\n";
    else
        cout << "No\n";

    return 0;
}