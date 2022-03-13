#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[1000000];
int b[1000000];
int r[2000000];
void merge(int len1, int len2){
    int i0 = 0;
    int i1 = 0;
    int i2 = 0;
    while(i1 < len1 && i2 < len2)
        if(a[i1] < b[i2])
            r[i0++] = a[i1++];
        else
            r[i0++] = b[i2++];
    
    while(i1 < len1)
        r[i0++] = a[i1++];
    while(i2 < len2)
        r[i0++] = b[i2++];
    for(int i=0; i<n+m; i++) cout << r[i] << " ";
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<m; i++) cin >> b[i];
    merge(n, m);
    return 0;
}