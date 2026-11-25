#include <bits/stdc++.h>
using namespace std;
string s;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> s;
    for(int i=1; i<=s.length(); i++){
        cout << s[i-1];
        if(i % 10 == 0 && i != 0)
            cout << "\n";
    }

    return 0;
}