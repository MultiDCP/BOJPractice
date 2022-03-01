#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a[3];
    int max = -1;
    
    for(int i=0; i<3; i++){
        cin >> a[i];
        if(max < a[i])
            max = a[i];
    }

    if(a[0] == a[1] && a[1] == a[2])
        cout << 10000 + a[0] * 1000;
    else{
        if(a[0] == a[1] || a[0] == a[2])
            cout << 1000 + a[0] * 100;
        else if(a[1] == a[2])
            cout << 1000 + a[1] * 100;
        else
            cout << max * 100;
    }

    return 0;
}