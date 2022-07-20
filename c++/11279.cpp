#include <bits/stdc++.h>
using namespace std;
int n;
priority_queue<int> pq;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        if(x == 0)
            if(pq.empty())
                cout << 0 << "\n";
            else{
                cout << pq.top() << "\n";
                pq.pop();
            }
        else
            pq.push(x);
    }    

    return 0;
}

/*
강의를 보면서 힌트를 얻어 풀음. 복습 및 반복 연습, 세부 과정 이해 필요.
*/