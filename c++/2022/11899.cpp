#include <bits/stdc++.h>
using namespace std;
int res;
string n;
stack<char> s;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i=0; i<n.length(); i++){
        if(!s.empty() && (s.top() == '(' && n[i] == ')')){
            s.pop();
        }
        else
            s.push(n[i]);
    }

    while(!s.empty()){
        res++;
        s.pop();
    }
    cout << res << "\n";

    return 0;
}