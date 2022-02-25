#include <bits/stdc++.h>
using namespace std;

int arr[26];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    
    string c;
    cin >> c;
    
    stack<double> s;
    
    for(int i=0; i<n; i++){
        double temp;
        cin >> temp;
        arr[i] = temp;
    }
    
    for(int i=0; i<c.length(); i++){
        if(c[i] >= 'A' && c[i] <= 'Z'){
            s.push(arr[c[i] - 'A']);
        }
        else {
            if(!s.empty()){
                double t1 = s.top();
                s.pop();
                double t2 = s.top();
                s.pop();
                if(c[i] == '*'){
                    s.push(t2 * t1);
                }
                else if(c[i] == '/'){
                    s.push(t2 / t1);
                }
                else if(c[i] == '+'){
                    s.push(t2 + t1);
                }
                else if(c[i] == '-'){
                    s.push(t2 - t1);
                }
            }
        }
    }
    
    cout << fixed;
    cout.precision(2);
    cout << s.top() << '\n';

    return 0;
}

/*
푸는 데 시간이 다소 걸린 이유
알고리즘 설계 자체는 나쁘지 않았다. 잘 고심했음.
헌데 double을 int로 계산하는 실수를 하여
중간 풀이 과정에서 오차가 발생하기도 했다.
이를 고치는 과정에서 시간 낭비가 생긴 것이다.
그러나 잘 풀었다.
같은 크기의 메모리를 사용한 다른 사람들보다 코드 길이가 더 짧다.
다만 제출 과정에서 쓰지 않은 변수를 그대로 남겨둔 점은 아쉽다.
*/