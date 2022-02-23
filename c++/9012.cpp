#include <bits/stdc++.h>
using namespace std;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    for(int i=0; i<t; i++){
        stack<char> s;
        string m;
        cin >> m;

        for(int j=0; j<m.length(); j++){
            if(m[j] == '(')
                s.push('(');
            else {
                if(s.empty())
                    s.push(')');
                else
                    if(s.top() == '(')
                        s.pop();
            }
        }

        if(s.empty())
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}