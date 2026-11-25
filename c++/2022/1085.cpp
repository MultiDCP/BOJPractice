#include <bits/stdc++.h>
using namespace std;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int x, y, w, h;
    cin >> x >> y >> w >> h;

    int a[4];
    a[0] = x; a[1] = w-x; a[2] = y; a[3] = h-y;

    cout << *min_element(a, a+4) << '\n';

    return 0;
}