#include <bits/stdc++.h>
using namespace std;
int a[3];
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for(int i=0; i<3; i++)
        cin >> a[i];
    
    sort(a, a+3);
    cout << a[1] << "\n";

    return 0;
}