#include <bits/stdc++.h>
using namespace std;

int n, m;
void func(vector<int> arr, int k){
    if(k == m){
        for(int i=0; i<m; i++)
            cout << arr[i] << " ";
        cout << "\n";
        return;
    }
    else
        for(int i=0; i<n; i++)
            if(!arr.empty() && i+1 < arr.back()) continue;
            else{
                arr.push_back(i+1);
                func(arr, k+1);
                arr.pop_back();
            }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> arr;

    cin >> n >> m;
    func(arr, 0);

    return 0;
}