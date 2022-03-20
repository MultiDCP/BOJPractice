#include <bits/stdc++.h>
using namespace std;
int n;
int a[1000];
int d[1000];
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i=0; i<n; i++)
        cin >> a[i];
    d[0] = 1;
    for(int i=1; i<n; i++){
        if(a[i-1] < a[i]) d[i] = d[i-1] + 1;
        else{
            d[i] = 1;
            int max = 0;
            for(int j=i-1; j>=0; j--){
                if(a[i] <= a[j] && max >= a[j]) continue;
                else{
                    d[i] = d[j] + 1;
                    max = a[j];
                }
            }
        }
    }
    for(int i=0; i<n; i++)
        cout << d[i] << " ";
    cout << "\n";
    cout << *max_element(d, d+n);

    return 0;
}