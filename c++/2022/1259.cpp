#include <bits/stdc++.h>
using namespace std;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while(true){
        int n;
        cin >> n;
        if(n == 0){
            break;
        }

        string s1 = to_string(n);
        string s2 = s1;
        reverse(s2.begin(), s2.end());
        if(s1 == s2){
            cout << "yes\n";
        }
        else{
            cout << "no\n";
        }
    }

    return 0;
}