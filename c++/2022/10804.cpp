#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a[21];
    for(int i=1; i<=20; i++)
        a[i] = i;
    a[0] = 0;
    
    for(int i=0; i<10; i++){
        int n, m;
        cin >> n >> m;
        reverse(a+n, a+m+1);
    }

    for(int i=1; i<=20; i++)
        cout << a[i] << " ";

    return 0;
}