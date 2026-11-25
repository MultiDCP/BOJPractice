#include <iostream>
#include <string>
using namespace std;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b;
    cin >> a >> b;

    string strA, strB;
    string tmpA, tmpB;
    int newA, newB;

    strA = to_string(a);
    strB = to_string(b);

    for(int i=0; i<3; i++){
        tmpA[i] = strA[2-i];
        tmpB[i] = strB[2-i];
    }

    newA = stoi(tmpA);
    newB = stoi(tmpB);

    if(newA >= newB){
        cout << newA << '\n';
    }
    else{
        cout << newB << '\n';
    }

    return 0;
}