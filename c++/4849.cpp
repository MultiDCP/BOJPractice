#include <bits/stdc++.h>
using namespace std;
#define MAX 246913
int n;
vector<bool> v(MAX);
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    v[1] = false;
    for(int i=2; i<MAX; i++)
        v[i] = true;
    for(int i=2; i*i<MAX; i++)
        for(int j=i*i; j<MAX; j+=i)
            if(v[j] && j % i == 0) v[j] = false;
    
    while(true){
        cin >> n;
        if(n == 0) break;
        int res = 0;
        for(int i=n+1; i<=2*n; i++)
            if(v[i]) res++;
        cout << res << "\n";
    }

    return 0;
}