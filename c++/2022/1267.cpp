#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    int y = 0;
    int m = 0;
    for(int i=0; i<n; i++){
        int c;
        cin >> c;
        y += (10 + 10 * (c / 30));
        m += (15 + 15 * (c / 60));
    }

    if(y > m)
        cout << "M " << m;
    else if(y < m)
        cout << "Y " << y;
    else
        cout << "Y M " << y;

    return 0;
}