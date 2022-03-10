#include <bits/stdc++.h>
using namespace std;
int n, m;
int origin[8];
int isUsed[8];
int selected[8];
int compare[8];
void func(int selected[], int compare[], int k){
    if(k == m){
        for(int i=0; i<m; i++) cout << selected[i] << " ";
        cout << "\n";
    }
    else{
        for(int i=0; i<n; i++){
            if(!isUsed[i]){
                selected[k] = origin[i];
                if(selected[k] == compare[k]) continue;
                compare[k] = origin[i];
                isUsed[i] = 1;
                func(selected, compare, k+1);
                isUsed[i] = 0;
            }
        }
        compare[k] = 0;
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
    func(selected, compare, 0);
    return 0;
}