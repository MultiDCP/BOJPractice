#include <bits/stdc++.h>
using namespace std;
int n, k;
int a[1000];
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cout << fixed;
    cout.precision(3);

    cin >> n;
    for(int i=0; i<n; i++){
        double avg = 0;
        cin >> k;
        for(int j=0; j<k; j++){
            cin >> a[j];
            avg += a[j];
        }
        avg /= k;
        double tmp = 0;
        for(int j=0; j<k; j++)
            if(avg < a[j]) ++tmp;
        cout << tmp / k * 100 << "%\n";
    }

    return 0;
}