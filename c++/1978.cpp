#include <bits/stdc++.h>
using namespace std;
int n, res;
vector<bool> v(1001, true);
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    v[1] = 0;
    for(int i=2; i*i<=1000; i++)
        if(v[i])
            for(int j=i*i; j<=1000; j=j+i)
                v[j] = 0;
    for(int i=0; i<n; i++){
        int tmp;
        cin >> tmp;
        if(v[tmp]) res++;
    }
    cout << res;
    return 0;
}