#include <bits/stdc++.h>
using namespace std;
int a[5];
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int sum = 0;

    for(int i=0; i<5; i++){
        cin >> a[i];
        sum += a[i];
    }

    sort(a, a+5);
    cout << sum / 5 << "\n" << a[2];

    return 0;
}