#include <bits/stdc++.h>
using namespace std;
string s, newS;
stack<char> st;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    getline(cin, s);
    for(int i=0; i<s.length(); i++){
        if(s[i] == '<'){
            while(!st.empty()){
                newS += st.top();
                st.pop();
            }

            while(s[i] != '>'){
                newS += s[i++];
            }
            newS += '>';
        }
        else if(s[i] == ' '){
            while(!st.empty()){
                newS += st.top();
                st.pop();
            }
            newS += ' ';
        }
        else
            st.push(s[i]);
    }
    while(!st.empty()){
        newS += st.top();
        st.pop();
    }
    cout << newS;

    return 0;
}