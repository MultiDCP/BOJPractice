#include <iostream>
using namespace std;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long a, b;
    cin >> a >> b;

    cout << a+b << '\n' << a-b << '\n' << a*b << '\n' << a/b << '\n' << a%b << '\n';
    return 0;
}