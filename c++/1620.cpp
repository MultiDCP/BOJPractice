#include <bits/stdc++.h>
using namespace std;
int n, m;
unordered_map<string, int> h1;
unordered_map<int, string> h2;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    int cnt = 1;
    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        h1[s] = cnt;
        h2[cnt++] = s;
    }

    for(int i=0; i<m; i++){
        string s;
        cin >> s;
        
        bool isNumber = true;
        for(int i=0; i<s.length(); i++){
            if(!isdigit(s[i]))
                isNumber = false;
        }

        if(isNumber)
            cout << h2[stoi(s)] << "\n";
        else
            cout << h1[s] << "\n";
    }

    return 0;
}