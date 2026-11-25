#include <bits/stdc++.h>
using namespace std;

int n, m;
int orig[8];
int used[8];
int arr[8];
int comp[8];
void func(int arr[], int comp[], int k){
    if(k == m){
        for(int i=0; i<m; i++) cout << arr[i] << " ";
        cout << "\n";
    }
    else{
        for(int i=0; i<n; i++){
            if(!used[i]){
                if(k > 0)
                    if(arr[k-1] > orig[i]) continue;
                arr[k] = orig[i];
                if(comp[k] == orig[i]) continue;
                used[i] = 1;
                comp[k] = orig[i];
                func(arr, comp, k+1);
                used[i] = 0;
            }
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