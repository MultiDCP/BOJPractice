#include <bits/stdc++.h>
using namespace std;
string s;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    getline(cin, s);
    string newS;
    for(int i=0; i<s.length(); i++){
        if(s[i] >= 'A' && s[i] <= 'Z')
            newS.push_back(s[i]);
    }
    stack<char> st;
    for(int i=0; i<newS.length(); i++){
        if(st.empty() && newS[i] == 'U')
            st.push(newS[i]);
        else if((st.size() == 1 || st.size() == 3) && newS[i] == 'C')
            st.push(newS[i]);
        else if(st.size() == 2 && newS[i] == 'P')
            st.push(newS[i]);
    }

    if(st.size() == 4)
        cout << "I love UCPC\n";
    else
        cout << "I hate UCPC\n";

    return 0;
}