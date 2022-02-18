#include <iostream>

using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b;

    cin >> a >> b;

    if(a > b){
        cout << ">" << endl;
    } else if (a == b){
        cout << "==" << endl;
    } else {
        cout << "<" << endl;
    }

    return 0;
}