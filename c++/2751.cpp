#include <bits/stdc++.h>
using namespace std;
int n;
int arr[1000000];
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i=0; i<n; i++) cin >> arr[i];
    sort(arr, arr+n);
    for(int i=0; i<n; i++) cout << arr[i] << "\n";
    return 0;
}