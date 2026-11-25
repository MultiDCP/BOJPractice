#include <bits/stdc++.h>
using namespace std;
string s;
vector<char> v;
bool compare(char a, char b){
    return b < a;
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> s;
    for(int i=0; i<s.length(); i++)
        v.push_back(s[i]);
    sort(v.begin(), v.end(), compare);
    for(int i=0; i<s.length(); i++)
        cout << v[i];

    return 0;
}