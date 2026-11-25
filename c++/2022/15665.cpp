#include <bits/stdc++.h>
using namespace std;

int n, m;
int orig[7];
int arr[7];
int comp[7];
void func(int arr[], int comp[], int k){
    if(k == m){
        for(int i=0; i<m; i++) cout << arr[i] << " ";
        cout << "\n";
    }
    else{
        for(int i=0; i<n; i++){
            arr[k] = orig[i];
            if(comp[k] == orig[i]) continue;
            comp[k] = orig[i];
            func(arr, comp, k+1);
        }
        comp[k] = 0;
    }
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for(int i=0; i<n; i++)
        cin >> orig[i];
    sort(orig, orig+n);
    func(arr, comp, 0);
    return 0;
}