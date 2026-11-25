#include <bits/stdc++.h>
using namespace std;
unordered_map<string, string> h;
int n, m;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for(int i=0; i<n; i++){
        string a, b;
        cin >> a >> b;
        h[a] = b;
    }

    for(int i=0; i<m; i++){
        string c;
        cin >> c;
        cout << h[c] << "\n";
    }

    return 0;
}