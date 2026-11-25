#include <bits/stdc++.h>
using namespace std;
string s;
int zo[2];
stack<char> st;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> s;
    for(int i=0; i<s.length(); i++){
        if(st.empty()){
            st.push(s[i]);
            zo[s[i]-'0']++;
        }
        else if(st.top() != s[i]){
            if(st.top() == '1')
                zo[0]++;
            else
                zo[1]++;
            st.push(s[i]);
        }

    }
    cout << min(zo[0], zo[1]) << "\n";

    return 0;
}