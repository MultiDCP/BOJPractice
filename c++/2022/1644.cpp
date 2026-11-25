#include <bits/stdc++.h>
using namespace std;
int n, en, sum, res;
vector<bool> v(4000001);
vector<int> a;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i=2; i<=n; i++)
        v[i] = true;
    for(int i=2; i*i<=n; i++)
        for(int j=i*i; j<=n; j+=i)
            if(j % i == 0 && v[j]) v[j] = false;
    for(int i=2; i<=n; i++)
        if(v[i])
            a.push_back(i);

    int s = a.size();
    for(int st=0; st<s; st++){
        while(en < s && sum < n){
            sum += a[en];
            en++;
        }
        if(sum == n) res++;
        sum -= a[st];
    }
    cout << res;
    
    return 0;
}