#include <bits/stdc++.h>

using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    for(int i=n; i>0; i--){
        for(int j=n; j>i; j--)
            cout << " ";
        for(int j=2*i-1; j>0; j--)
            cout << "*";
        cout << "\n";
    }

    return 0;
}