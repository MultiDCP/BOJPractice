#include <bits/stdc++.h>
using namespace std;

int arr[100000];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string c;
    cin >> c;
    
    //stack<int> s;
    int result = 0;
    int pos = -1;
    
    for(int i=1; i<=c.length(); i++){
        if(c[i-1] == '('){
            if(c[i] == ')')
                for(int j=0; j<=pos; j++)
                    ++arr[j];   
            else
                ++arr[++pos];
        }
        else if(c[i-1] == ')' && c[i-2] != '('){
            result += arr[pos];
            arr[pos--] = 0;
        }
    }
    
    cout << result << '\n';

    return 0;
}

/*
아마 지금까지 짠 코드들 중에서 제일 비효율적 접근이 아니었을까.
사실 스택을 쓸 것도 굳이 없었던 문제였다.
파이프를 늘리고 만약 자르는 칸이 뜨면 result에 그만큼 더하고
()가 아니면서 )이면 그만큼 파이프가 끝난 거니 1을 더하고
그런 식으로 접근했으면 훨씬 효율적으로, 훨씬 빠르게 풀 수 있었다.
스택을 다 꺼내서 뒤집는다던가, 스택 내에 모든 값을 더하려고 한다던가
이런 식의 불필요한 시간 낭비와 메모리 낭비가 더해져 좋지 않은 값을 냈다.
사실상 틀렸다고 볼 수 있는 문제.
*/