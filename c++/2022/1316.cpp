#include <bits/stdc++.h>
using namespace std;
int n, res;
string s;
vector<bool> v(26);
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i=0; i<n; i++){
        fill(v.begin(), v.end(), false);
        cin >> s;
        bool isGroup = true;
        for(int j=0; j<s.length(); j++)
            if(!v[s[j]-'a'])
                v[s[j]-'a'] = true;
            else
                if(s[j] != s[j-1]) isGroup = false;
        if(isGroup) ++res;
    }
    cout << res;

    return 0;
}