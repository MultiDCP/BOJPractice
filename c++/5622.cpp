#include <bits/stdc++.h>
using namespace std;
string s;
int n;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> s;
    for(int i=0; i<s.length(); i++)
        if(s[i] >= 'A' && s[i] <= 'C')
            n += 3;
        else if(s[i] >= 'D' && s[i] <= 'F')
            n += 4;
        else if(s[i] >= 'G' && s[i] <= 'I')
            n += 5;
        else if(s[i] >= 'J' && s[i] <= 'L')
            n += 6;
        else if(s[i] >= 'M' && s[i] <= 'O')
            n += 7;
        else if(s[i] >= 'P' && s[i] <= 'S')
            n += 8;
        else if(s[i] >= 'T' && s[i] <= 'V')
            n += 9;
        else if(s[i] >= 'W' && s[i] <= 'Z')
            n += 10;
    cout << n;

    return 0;
}