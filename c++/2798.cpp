#include <bits/stdc++.h>
using namespace std;
int n, m;
int maxE = -1;
int a[100];
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for(int i=0; i<n; i++)
        cin >> a[i];
    for(int i=0; i<n-2; i++){
        for(int j=i+1; j<n-1; j++){
            for(int k=j+1; k<n; k++){
                int tmp = a[i] + a[j] + a[k];
                if(tmp <= m && tmp > maxE)
                    maxE = tmp;
            }
        }
    }
    cout << maxE;
    return 0;
}