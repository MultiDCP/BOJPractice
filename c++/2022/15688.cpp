// use counting sort
#include <bits/stdc++.h>
using namespace std;
int n;
int arr[2000001];
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i=0; i<n; i++){
        int tmp;
        cin >> tmp;
        arr[tmp+1000000]++;
    }
    for(int i=0; i<2000001; i++)
        for(int j=0; j<arr[i]; j++)
            cout << i-1000000 << "\n";

    return 0;
}