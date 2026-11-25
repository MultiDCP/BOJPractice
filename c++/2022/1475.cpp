#include <bits/stdc++.h>
using namespace std;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int a[9] = {0, };

    string s;
    cin >> s;

    for(int i=0; i<s.length(); i++){
        if(s[i] == '6' || s[i] == '9'){
            ++a[6];
        }
        else{
            ++a[s[i] - '0'];
        }
    }

    int max = -1;
    for(int i=0; i<9; i++){
        if(i != 6){
            if(a[i] > max){
                max = a[i];
            }
        }
        else{
            int temp = -1;
            if(a[i] != 0 && a[i] >= 2){
                if(a[i] % 2 == 0){
                    temp = a[i] / 2;
                }
                else{
                    temp = a[i] / 2 + 1;
                }
            }
            else if(a[i] == 0){
                temp = 0;
            }
            else if(a[i] == 1){
                temp = 1;
            }

            if(temp > max){
                max = temp;
            }
        }
    }
    
    cout << max << '\n';

    return 0;
}

/*
코드 단축을 위한 방법
1. string을 쓰지 않는 대신 int로만 해도 될듯.
a[s%10]++;
s/=10;

2. maxVar = max(maxVar, a[i]) 라는 좋은 메소드가 있다.
6/9를 제외한 나머지 값들의 max값을 비교한 후
그 다음에 6/9 배열의 값을 더해 2로 나눈 값의 몫과 나머지를 더해서
이를 max와 비교하면 된다.

하...
*/