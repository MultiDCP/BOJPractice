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

/*
오답 정리
핵심 : 스택은 우선순위가 낮은 연산자부터 큰 연산자 순으로 쌓여야 한다.
A~Z는 무조건 출력하며, 연산자만 스택에 넣어주면 된다.
문자열을 쭉 따라가면서 연산자를 스택에 넣고 빼는 연산을 반복해주면 됐다.
-> 한 마디로, 나처럼 스택을 3개까지 만들 필요가 전혀 없었음.
스택은 연산자를 넣어주는 스택 하나만 있었어도 충분했다.
헌데 나는 문자를 따로 고려하고 스택을 풀고 있었으며,
문제풀이 막판에서야 r 스택이 굳이 필요가 없이
그냥 바로 출력해주면 된다는 사실을 뒤늦게 깨달을 수 있었다.
또한 값을 미리 만들고 결과를 출력해야겠다는 고정관념에 사로잡혀
값을 애써 저장하려고 애를 쓰다가 결국 많은 부분이 꼬였다.
입력 1개에 출력 1개면 값은 그냥 즉석에서 바로 뽑는 게 오히려 복잡도 면에서 낫다.
그리고 모든 경우에서 스택이 비었는지 여부도 확인하는 게 맞다.
다른 거 풀 때도 비슷하게 생각하는 것이 중요할 거 같다.
*/