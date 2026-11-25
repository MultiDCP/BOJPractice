#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    stack<int> a;
    stack<int> index;
    cin >> n;
    for(int i=1; i<=n; i++){
        int temp;
        cin >> temp;

        if(a.empty()){
            cout << "0 ";
            a.push(temp);
            index.push(i);
        }
        else{
            if(a.top() < temp){
                while(!a.empty() && (a.top() < temp)){
                    a.pop();
                    index.pop();
                }

                if(!a.empty()){
                    cout << index.top() << " ";
                }
                else{
                    cout << "0 ";
                }
                a.push(temp);
                index.push(i);
            }
            else{
                cout << index.top() << " ";
                a.push(temp);
                index.push(i);
            }
        }
    }

    return 0;
}

/*
'내림차순'이라는 힌트가 많은 도움이 됐다.
인덱스와 값을 동시에 저장한 것은 좋은 선택이었음.
물론 실전에서 이런 힌트를 주진 않을테니
그런 차이와 규칙을 내가 찾는 것이 중요할 것이다.
*/