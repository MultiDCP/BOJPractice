#include <bits/stdc++.h>
using namespace std;

int isValid(string s){
    stack<char> st;

    for(int i=0; i<s.length(); i++){
        if(s[i] == '('){
            st.push('(');
        }
        else if(s[i] == '['){
            st.push('[');
        }
        else if(s[i] == ')'){
            if(!st.empty() && st.top() == '('){
                st.pop();
            }
            else{
                break;
            }
        }
        else if(s[i] == ']'){
            if(!st.empty() && st.top() == '['){
                st.pop();
            }
            else{
                break;
            }
        }
    }

    if(st.empty()){
        return 1;
    }
    else{
        return 0;
    }
}

int paren(string s){
    if(s == "[]")
        return 3;
    else if(s == "()")
        return 2;
    else{
        
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string c;
    cin >> c;

    int result = 0;
    int temp = 0;
    
    if(isValid(c) == 1){
        result = paren(c);
    }
    else{
        cout << 0;
    }

    return 0;
}

/*
오답 풀이
"분배 법칙"을 활용하면 된다
아
(()[[]]) 를 풀은 2 * (2 + 3 * 3) 의 경우
(2 * 2) + (2 * 3 * 3) 으로 바뀐다.
왼쪽 괄호가 나오면 temp에 2나 3을 곱한 뒤 스택에 괄호를 push하고
오른쪽 괄호가 나오면 temp를 2나 3으로 나눈 뒤 스택에서 pop한다.
() 나 []의 경우 temp를 나눠주기 전에 answer에 더한다.
괄호를 닫는 과정에서 스택 상태와 이전 문자를 보고 케이스를 구분한다.
()가 아닌 ) 라면 이미 temp에 값이 곱해진 상황으로 answer에 더해줄 필요는 없다.
*/