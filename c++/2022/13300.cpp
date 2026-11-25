#include <bits/stdc++.h>
using namespace std;

int a[12];
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;

    for(int i=0; i<n; i++){
        int s, y;
        cin >> s >> y;
        ++a[2*(y-1)+s];
    }
    int result = 0;
    for(int i=0; i<12; i++){
        if(a[i] == 0) continue;
        else if(a[i] % k != 0) result += ((a[i] / k) + 1);
        else result += (a[i] / k);
    }
    cout << result;

    return 0;
}