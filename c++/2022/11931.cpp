#include <bits/stdc++.h>
using namespace std;
int n;
int a[1000000];
bool compare(int a, int b){
    return b < a;
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> a[i];
    sort(a, a+n, compare);
    for(int i=0; i<n; i++)
        cout << a[i] << "\n";
    
    return 0;
}