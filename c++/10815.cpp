#include <bits/stdc++.h>
using namespace std;
int n, m, tmp;
int a[500000];
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i=0; i<n; i++)
        cin >> a[i];
    sort(a, a+n);
    cin >> m;
    for(int i=0; i<m; i++){
        cin >> tmp;
        if(binary_search(a, a+n, tmp))
            cout << "1 ";
        else
            cout << "0 ";
    }

    return 0;
}