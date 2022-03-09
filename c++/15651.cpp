#include <bits/stdc++.h>
using namespace std;

int n, m;
void func(vector<int> v, int k){
    if(m == k){
        for(int i=0; i<m; i++)
            cout << v[i] << " ";
        cout << "\n";
        return;
    }
    for(int i=0; i<n; i++){
        v.push_back(i+1);
        func(v, k+1);
        v.pop_back();
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    vector<int> v;
    func(v, 0);

    return 0;
}