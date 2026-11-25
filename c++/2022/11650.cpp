#include <bits/stdc++.h>
using namespace std;
int n;
pair<int, int> p[100000];
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i=0; i<n; i++){
        int x, y;
        cin >> x >> y;
        p[i] = {x, y};
    }
    sort(p, p+n);
    for(int i=0; i<n; i++)
        cout << p[i].first << " " << p[i].second << "\n";
    return 0;
}