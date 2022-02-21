#include <bits/stdc++.h>
using namespace std;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    int temp[n];
    for(int i=0; i<n; i++){
        temp[i] = 1;
    }

    int arr[n];
    int original_k = k;

    for(int i=0; i<n; i++){
        temp[k-1] = 0;
        arr[i] = k;

        int count = 0;
        while(count != original_k && i != n-1){
            k++;
            if(k > n){
                k -= n;
            }
            if(temp[k-1] != 0){
                count++;
            }
        }
    }

    cout << '<';
    for(int i=0; i<n; i++){
        cout << arr[i];
        if(i != n-1)
            cout << ", ";
    }
    cout << '>' << '\n';

    return 0;
}