#include <bits/stdc++.h>
using namespace std;
stack<char> s;
string str;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while(true){
        getline(cin, str);
        if(str == ".") break;
        for(int i=0; i<str.length(); i++)
            if(str[i] == '(')
                s.push('(');
            else if(str[i] == '[')
                s.push('[');
            else if(str[i] == ')')
                if(!s.empty() && s.top() == '(')
                    s.pop();
                else s.push(')');
            else if(str[i] == ']')
                if(!s.empty() && s.top() == '[')
                    s.pop();
                else s.push(']');
        if(s.empty()) cout << "yes\n";
        else {
            cout << "no\n";
            while(!s.empty())
                s.pop();
        }
    }

    return 0;
}