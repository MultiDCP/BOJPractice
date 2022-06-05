#include <bits/stdc++.h>
using namespace std;
string a, b;
string SumString(string a, string b){
    if(a.length() < b.length())
        swap(a, b);
    int ten = 0;
    string newStr = "";
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    for(int i=0; i<b.length(); i++){
        int newInt = int(a[i] - '0') + int(b[i] - '0') + ten;
        newStr += char(newInt % 10 + '0');
        ten = newInt /= 10;
    }
    for(int i=b.length(); i<a.length(); i++){
        int newInt = int(a[i] - '0') + ten;
        newStr += char(newInt % 10 + '0');
        ten = newInt /= 10;
    }
    if(ten == 1)
        newStr += '1';
    reverse(newStr.begin(), newStr.end());
    return newStr;
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> a >> b;
    cout << SumString(a, b);

    return 0;
}