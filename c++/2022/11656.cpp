#include <bits/stdc++.h>
using namespace std;
string s;
vector<string> v;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> s;
    for(int i=0; i<s.length(); i++){
        string tmp = s.substr(i);
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    for(int i=0; i<v.size(); i++)
        cout << v[i] << "\n";

    return 0;
}