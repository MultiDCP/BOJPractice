#include <bits/stdc++.h>
using namespace std;
int n;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    if(n % 2 == 1)
        cout << "SK";
    else
        cout << "CY";

    return 0;
}