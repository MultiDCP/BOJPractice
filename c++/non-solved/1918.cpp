#include <bits/stdc++.h>
using namespace std;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;

    stack<string> a;
    stack<string> n;
    stack<string> r;
    stack<string> t;

    for(int i=0; i<s.length(); i++){
        string temp = "";
        temp += s[i];
        if(s[i] >= 'A' && s[i] <= 'Z'){
            a.push(temp);
        }
        else if(s[i] == '+' || s[i] == '-' || s[i] == '*' ||
                s[i] == '/' || s[i] == '(' || s[i] == ')'){
            n.push(temp);
        }
    }

    while(!a.empty() && !n.empty()){
        if(n.top() == ")"){

        }
        else if(n.top() == "*" || n.top() == "/"){
            string result = "";

            string t1 = a.top();
            a.pop();
            string t2 = a.top();
            a.pop();
            result += t2 + t1 + n.top();
            n.pop();

            if(!t.empty()){ // t에 아직 값이 있음
                while(!t.empty()){
                    result += r.top();
                    r.pop();
                }
            }

            if(a.empty()){
                r.push(result);
            }
            else{
                a.push(result);
            }
        }
        else if(n.top() == "+" || n.top() == "-"){
            string tn = n.top();
            n.pop();
            if(!n.empty()){
                if(n.top() == "*" || n.top() == "/"){
                    t.push(tn);
                    t.push(a.top());
                    a.pop();
                }
            }
            else{
                string result = "";

                string t1 = a.top();
                a.pop();
                string t2 = a.top();
                a.pop();
                result += t2 + t1 + tn;
                if(a.empty()){
                    r.push(result);
                }
                else{
                    a.push(result);
                }
            }
        }
    }

    string result = "";
    while(!r.empty()){
        result += r.top();
        r.pop();
    }
    cout << result << '\n';

    return 0;
}