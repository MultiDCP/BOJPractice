#include <iostream>
#include <string>
using namespace std;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int a;
    string s;
    int result = 0;

    cin >> a;
    cin >> s;

    for(int i=0; i<a; i++){
        result += int(s[i] - '0');
    }

    cout << result << '\n';

    return 0;
}