#include <bits/stdc++.h>
using namespace std;
string a, b;
string BigSum(string a, string b){
    int sum = 0;
    string newString = "";
    while(!a.empty() || !b.empty() || sum != 0){
        if(!a.empty()){
             sum += a.back() - '0';
             a.pop_back();
        }
        if(!b.empty()){
            sum += b.back() - '0';
            b.pop_back();
        }
        newString.push_back(sum % 10 + '0');
        sum /= 10;
    }
    reverse(newString.begin(), newString.end());
    return newString;
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> a >> b;
    cout << BigSum(a, b);

    return 0;
}
