#include <bits/stdc++.h>
using namespace std;
int n, k;
vector<int> v;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;
    for(int i=1; i*i<=n; i++)
        if(n % i == 0) v.push_back(i);
    
    if(v.back() * v.back() == n)
        for(int i=v.size()-2; i>=0; i--)
            v.push_back(n / v[i]);
    else
        for(int i=v.size()-1; i>=0; i--)
            v.push_back(n / v[i]);

    if(k > v.size()) cout << 0;
    else
        cout << v[k-1];
    return 0;
}

/*
보완
14~19줄은
for(int i=v.size()-1; i>=0; i--){
    if(v[i]*v[i] == n) continue;
    v.push_back(n/v[i]);
}
로 줄일 수 있다. 굳이 조건 나눌 필요 없음
*/