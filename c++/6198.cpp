#include <bits/stdc++.h>
using namespace std;

#define H first
#define I second

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    stack<pair<int, int>> s;
    long long result = 0;

    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        int h;
        cin >> h;
        if(s.empty())
            s.push({h, i});
        else{
            if(h >= s.top().H)
                while(!s.empty() && h >= s.top().H){
                    result += (i - s.top().I - 1);
                    s.pop();
                }
            s.push({h, i});
        }
    }
    if(!s.empty()){
        auto cur = s.top();
        while(!s.empty()){
            result += (cur.I - s.top().I);
            s.pop();
        }
    }
    cout << result;

    return 0;
}

/*
오답 이유
1. 최대 80000개, 10^9~10^9-80000의 수를 더했을 때
integer overflow가 날 가능성이 있음을 고려하지 못함
2. 자신보다 작은 빌딩의 수를 카운트하는 과정에서
이전에는 벡터를 사용해 일일이 1을 더하는 과정을 사용했는데
이렇게 될 경우 매번 n번의 연산이 발생해 시간이 기하급수적으로 늘어난다
스택만을 사용하여 인덱스를 저장하여 해결함
*/