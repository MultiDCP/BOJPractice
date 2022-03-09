#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> a;
void func(int isUsed[], vector<int> v, int k){
    if(k == m){
        for(int i=0; i<m; i++)
            cout << v[i] << " ";
        cout << "\n";
        return;
    }
    for(int i=0; i<n; i++){
        if(v.empty() || !isUsed[i]){
            v.push_back(a[i]);
            isUsed[i] = 1;
            func(isUsed, v, k+1);
            v.pop_back();
            isUsed[i] = 0;
        }
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    int isUsed[n];
    vector<int> v;
    for(int i=0; i<n; i++){
        int tmp;
        cin >> tmp;
        a.push_back(tmp);
        isUsed[i] = 0;
    }
    sort(a.begin(), a.end());
    func(isUsed, v, 0);

    return 0;
}