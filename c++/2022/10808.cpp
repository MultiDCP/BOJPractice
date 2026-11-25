#include <bits/stdc++.h>
using namespace std;
int a[26];
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;

    for(int i=0; i<s.length(); i++){
        a[s[i]-'a']++;
    }

    for(int i=0; i<26; i++){
        cout << a[i] << " ";
    }
    cout << '\n';

    return 0;
}