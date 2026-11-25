#include <bits/stdc++.h>
using namespace std;
int n;
string arr[50];
bool compare(string a, string b){
    if(a.length() != b.length())
        return a.length() < b.length();
    else{
        int tm1 = 0;
        int tm2 = 0;
        for(int i=0; i<a.length(); i++){
            if(a[i] >= '0' && a[i] <= '9')
                tm1 += a[i] - '0';
            if(b[i] >= '0' && b[i] <= '9')
                tm2 += b[i] - '0';
        }
        if(tm1 == tm2) return a < b;
        else return tm1 < tm2;
    }
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i=0; i<n; i++)
        cin >> arr[i];
    
    sort(arr, arr+n, compare);
    for(int i=0; i<n; i++)
        cout << arr[i] << "\n";

    return 0;
}