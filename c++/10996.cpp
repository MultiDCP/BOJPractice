#include <bits/stdc++.h>
using namespace std;
int n;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i=1; i<=n*2; i++){
        if(i % 2 == 0){
            for(int j=0; j<n/2; j++)
                cout << " *";
            cout << "\n";
        }
        else{
            for(int j=0; j<n/2; j++)
                cout << "* ";
            if(n % 2 == 1) cout << "*";
            cout << "\n";
        }
    }

    return 0;
}