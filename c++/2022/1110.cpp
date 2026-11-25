#include <bits/stdc++.h>
using namespace std;
int n, org, res;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    org = n;
    do{
        int rem;
        if(n < 10)
            rem = n;
        else
            rem = (n / 10 + n % 10) % 10;
        n = (n % 10) * 10 + rem;
        res++;
    }while(n != org);

    cout << res << "\n";

    return 0;
}