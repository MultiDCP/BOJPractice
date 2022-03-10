#include <bits/stdc++.h>
using namespace std;

int n, m;
int origin[8];
int selected[8];
void func(int selected[], int k){
    if(k == m){
        for(int i=0; i<m; i++) cout << selected[i] << " ";
        cout << "\n";
    }
    else{
        for(int i=0; i<n; i++){
            if(k == 0 || selected[k-1] <= origin[i]){
                selected[k] = origin[i];
                func(selected, k+1);
                selected[k] = 0;
            }
        }
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for(int i=0; i<n; i++)
        cin >> origin[i];
    sort(origin, origin+n);
    func(selected, 0);
    return 0;
}