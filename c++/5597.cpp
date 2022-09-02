#include <bits/stdc++.h>
using namespace std;
bool d[31];
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for(int i=1; i<=28; i++){
        int t;
        cin >> t;
        d[t] = true;
    }

    for(int i=1; i<=30; i++)
        if(d[i] == false)
            cout << i << "\n";

    return 0;
}