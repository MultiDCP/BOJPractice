#include <bits/stdc++.h>
using namespace std;
int n;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i=1; i<=1000000; i++){
        int res = i;
        string s = to_string(i);
        for(int j=0; j<s.length(); j++)
            res += int(s[j]-'0');
        if(res == n){
            cout << i;
            return 0;
        }
    }
    cout << 0;
    return 0;
}