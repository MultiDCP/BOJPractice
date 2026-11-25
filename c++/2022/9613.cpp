#include <bits/stdc++.h>
using namespace std;
#define ll long long
int t;
int a[100];
int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a%b);
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    for(int i=0; i<t; i++){
        int n;
        ll res = 0;
        cin >> n;
        for(int j=0; j<n; j++)
            cin >> a[j];

        vector<int> v;
        for(int j=0; j<n-1; j++)
            for(int k=j+1; k<n; k++)
                v.push_back(gcd(a[j], a[k]));

        for(int j=0; j<v.size(); j++)
            res += v[j];
        cout << res << "\n";
        memset(a, 0, sizeof(int)*100);
    }    

    return 0;
}