#include <bits/stdc++.h>
using namespace std;
int a[10];
int t;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    for(int i=0; i<t; i++){
        for(int j=0; j<10; j++)
            cin >> a[j];
        sort(a, a+10);
        cout << a[7] << "\n";
    }

    return 0;
}