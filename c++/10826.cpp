#include <bits/stdc++.h>
using namespace std;
string d[10001];
int n;
string SumString(string a, string b){
    int sum = 0;
    string result = "";
    if(a.length() < b.length())
        swap(a, b);
    while(a != "" && b != ""){
        int tmpA = a[a.length()-1] - '0';
        int tmpB = b[b.length()-1] - '0';
        sum += tmpA + tmpB;
        result += char(sum % 10 + '0');
        sum = sum / 10;
        a.pop_back();
        b.pop_back();
    }
    while(a != ""){
        sum += a[a.length()-1] - '0';
        result += char(sum % 10 + '0');
        sum = sum / 10;
        a.pop_back();
    }
    if(sum != 0)
        result += char(sum % 10 + '0');
    reverse(result.begin(), result.end());
    return result;
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    d[0] = "0";
    d[1] = "1";
    d[2] = "1";
    for(int i=3; i<=n; i++)
        d[i] = SumString(d[i-1], d[i-2]);
    cout << d[n];

    return 0;
}