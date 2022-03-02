#include <bits/stdc++.h>

using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    for(int i=n; i>0; i--){
        for(int j=0; j<n-i; j++)
            cout << " ";
        for(int j=0; j<2*i-1; j++)
            cout << "*";
        cout << "\n";
    }
    for(int i=2; i<=n; i++){
        for(int j=0; j<n-i; j++)
            cout << " ";
        for(int j=0; j<2*i-1; j++)
            cout << "*";
        cout << "\n";
    }
    
    return 0;
}

/*
출력 형식이 잘못된 이유
출력을 드래그해서 보면 뭔가... 다른 점을 볼 수 있다
그런 점도 하나하나 신경쓰는 편이 좋다
*/