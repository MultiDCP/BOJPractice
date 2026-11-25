#include <bits/stdc++.h>
using namespace std;

int a[26];
int b[26];
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string n, m;
    cin >> n >> m;
    for(int i=0; i<n.length(); i++)
        ++a[n[i] - 'a'];
    for(int i=0; i<m.length(); i++)
        ++b[m[i] - 'a'];
    
    int res = 0;
    
    for(int i=0; i<26; i++){
        if(a[i] == b[i]) continue;
        else if(a[i] > b[i])
            res += a[i] - b[i];
        else
            res += b[i] - a[i];
    }
    
    cout << res;

    return 0;
}