#include <bits/stdc++.h>
using namespace std;

int a[100];
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, v;
    cin >> n;

    for(int i=0; i<n; i++){
        int tmp;
        cin >> tmp;
        a[i] = tmp;
    }
    cin >> v;
    int result = 0;

    for(int i=0; i<n; i++){
        if(a[i] == v)
            result++;
    }
    cout << result;

    return 0;
}