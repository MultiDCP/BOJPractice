#include <bits/stdc++.h>
using namespace std;
stack<char> s;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string t;
    cin >> t;
    int temp = 1;
    int result = 0;
    for(int i=0; i<t.length(); i++){
        if(t[i] == '('){
            s.push('(');
            temp *= 2;
        }
        else if(t[i] == '['){
            s.push('[');
            temp *= 3;
        }
        else if(t[i] == ')'){
            if(!s.empty() && s.top() == '('){
                if(i > 0 && t[i-1] == '(')
                    result += temp;
                s.pop();
                temp /= 2;
            }
            else
                s.push(')');
        }
        else if(t[i] == ']'){
            if(!s.empty() && s.top() == '['){
                if(i > 0 && t[i-1] == '[')
                    result += temp;
                s.pop();
                temp /= 3;
            }
            else
                s.push(']');
        }
    }
    if(!s.empty())
        cout << 0;
    else
        cout << result;

    return 0;
}

/*
스택 문제를 풀 때 무조건 스택 안에서만 처리할 필요가 없다.
이런 문제는 '분배 법칙'을 파악해서
값을 필요할 때마다 곱해주거나 나눠주고 더해주면 된다.
이런 문제들의 유형을 잘 판단하자.
*/