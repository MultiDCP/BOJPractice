#include <bits/stdc++.h>
using namespace std;
int n;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    if(n == 1) return 0;
    int origN = n;
    for(int i=2; n!=1; i++){
        if(i*i > origN){
            cout << n;
            break;
        }
        while(n % i == 0){
            cout << i << "\n";
            n /= i;
        }
    }

    return 0;
}