#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n;
vector<ll> v;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        reverse(s.begin(), s.end());
        v.push_back(stoll(s));
    }
    sort(v.begin(), v.end());
    for(int i=0; i<v.size(); i++)
        cout << v[i] << "\n";

    return 0;
}