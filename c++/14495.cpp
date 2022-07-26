#include <bits/stdc++.h>
using namespace std;
int n;
string d[117];
string SumString(string a, string b){
    if(a.length() < b.length())
        swap(a, b);
    string res = "";

    int app = 0;
    int sum = 0;
    int idxA = a.length()-1;
    int idxB = b.length()-1;

    while(idxB >= 0){
        int newA = (a[idxA--] - '0');
        int newB = (b[idxB--] - '0');
        sum = app + newA + newB;
        res.push_back((sum % 10) + '0');
        app = sum / 10;
    }
    while(idxA >= 0){
        int newA = (a[idxA--] - '0');
        sum = app + newA;
        res.push_back((sum % 10) + '0');
        app = sum / 10;
    }
    if(app > 0)
        res.push_back(app + '0');
    reverse(res.begin(), res.end());
    return res;
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    d[1] = "1";
    d[2] = "1";
    d[3] = "1";
    for(int i=4; i<=n; i++)
        d[i] = SumString(d[i-1], d[i-3]);
    
    cout << d[n];

    return 0;
}