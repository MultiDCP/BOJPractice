#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int k;
    cin >> k;
    stack<int> s;
    for(int i=0; i<k; i++){
        int n;
        cin >> n;
        if(n == 0 && !s.empty())
            s.pop();
        else
            s.push(n);
    }
    int result = 0;
    while(!s.empty()){
        result += s.top();
        s.pop();
    }

    cout << result;

    return 0;
}