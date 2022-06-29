#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
unordered_map<string, int> m;
int n;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        auto pointPos = s.find('.');
        string extensionName = s.substr(pointPos+1);
        if(m.find(extensionName) == m.end())
            m[extensionName] = 1;
        else
            m[extensionName]++;
    }

    vector<pair<string, int>> v(m.begin(), m.end());
    sort(v.begin(), v.end());
    for(auto k : v)
        cout << k.F << " " << k.S << "\n";

    return 0;
}