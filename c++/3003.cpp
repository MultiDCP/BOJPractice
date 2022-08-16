#include <bits/stdc++.h>
using namespace std;
const int c[6] = {1, 1, 2, 2, 2, 8};
int d[6];
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for(int i=0; i<6; i++)
        cin >> d[i];
    
    for(int i=0; i<6; i++)
        cout << c[i] - d[i] << " ";

    return 0;
}