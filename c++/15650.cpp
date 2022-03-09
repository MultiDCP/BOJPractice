#include <bits/stdc++.h>
using namespace std;

int n, m;
void func(int isUsed[], vector<int> v, int k){
    if(k == m){
        for(int i=0; i<m; i++)
            cout << v[i] << " ";
        cout << "\n";
        return;
    }
    for(int i=0; i<n; i++){
        if(v.empty()){
            isUsed[i] = 1;
            v.push_back(i+1);
            func(isUsed, v, k+1);
            v.pop_back();
            isUsed[i] = 0;
        }
        else{
            if(isUsed[i] || v.back() >= i+1) continue;
            else{
                isUsed[i] = 1;
                v.push_back(i+1);
                func(isUsed, v, k+1);
                v.pop_back();
                isUsed[i] = 0;
            }
        }
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    int isUsed[n];
    for(int i=0; i<n; i++)
        isUsed[i] = 0;
    vector<int> v;
    func(isUsed, v, 0);

    return 0;
}