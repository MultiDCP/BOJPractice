#include <bits/stdc++.h>
using namespace std;
stack<char> s;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string p;
    cin >> p;
    for(int i=0; i<p.length(); i++){
        if(p[i] >= 'A' && p[i] <= 'Z') cout << p[i];
        else if(p[i] == '('){
            s.push(p[i]);
            int parCount = 1;
            while(s.top() != ')' || parCount > 1){
                i++;
                if(p[i] >= 'A' && p[i] <= 'Z') cout << p[i];
                else{
                    if(s.top() == ')'){
                        s.pop();
                        while(s.top() != '('){
                            cout << s.top();
                            s.pop();
                        }
                        parCount--;
                        s.pop();
                    }

                    if(p[i] == '(')
                        parCount++;
                    else if((p[i] == '+' || p[i] == '-' ) 
                        && (s.top() == '*' || s.top() == '/')){
                            while(s.top() != '('){
                                cout << s.top();
                                s.pop();
                            }
                    }
                    else{
                        if(!s.empty() && (s.top() == '+' || s.top() == '-')
                            && (p[i] == '+' || p[i] == '-')){
                            cout << s.top();
                            s.pop();
                        }
                        else if(!s.empty() && (s.top() == '*' || s.top() == '/')
                            && (p[i] == '*' || p[i] == '/')){
                                cout << s.top();
                                s.pop();
                            }
                    }
                    s.push(p[i]);
                }
            }
            s.pop();
            while(s.top() != '('){
                if(s.top() == '('){
                    s.pop();
                    parCount--;
                }
                else if (s.top() == ')') s.pop();
                else{
                    cout << s.top();
                    s.pop();
                }
            }
            s.pop();
        }
        else{
            if((p[i] == '+' || p[i] == '-' ) 
                && !s.empty() && (s.top() == '*' || s.top() == '/')){
                    while(!s.empty()){
                        cout << s.top();
                        s.pop();
                    }
                    s.push(p[i]);
            }
            else{
                if(!s.empty() && (s.top() == '+' || s.top() == '-')
                    && (p[i] == '+' || p[i] == '-')){
                    cout << s.top();
                    s.pop();
                }
                else if(!s.empty() && (s.top() == '*' || s.top() == '/')
                    && (p[i] == '*' || p[i] == '/')){
                        cout << s.top();
                        s.pop();
                    }
                s.push(p[i]);
            }
        }
    }
    while(!s.empty()){
        cout << s.top();
        s.pop();
    }

    return 0;
}
