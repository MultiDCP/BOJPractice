#include <bits/stdc++.h>
using namespace std;

int a[26];
int b[26];
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    for(int i=0; i<n; i++){
        string first, second;
        cin >> first >> second;
        bool isPossible = true;
        for(int j=0; j<first.length(); j++)
            ++a[first[j] - 'a'];
        for(int j=0; j<second.length(); j++)
            ++b[second[j] - 'a'];
        for(int j=0; j<26; j++){
            if(a[j] != b[j])
                isPossible = false;
            a[j] = 0; b[j] = 0;
        }
        if(isPossible) cout << "Possible\n";
        else cout << "Impossible\n";
    }

    return 0;
}