#include <bits/stdc++.h>
using namespace std;
int n, res;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i=0; i<n; i++){
        string s;
        stack<char> st;
        cin >> s;
        for(int j=0; j<s.length(); j++){
            if(!st.empty() && st.top() == s[j])
                st.pop();
            else
                st.push(s[j]);
        }
        if(st.empty())
            res++;
    }

    cout << res << "\n";

    return 0;
}