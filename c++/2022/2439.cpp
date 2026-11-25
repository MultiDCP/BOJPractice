#include <iostream>

using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;

    for(int i=1; i<=n; i++){
        for(int j=n-1; j>=i; j--){
            cout << " ";
        }
        for(int j=0; j<i; j++){
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}