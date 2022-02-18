#include <iostream>

using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int num;

    int sum = 0;

    for(int i=0; i<5; i++){
        cin >> num;
        sum += (num * num);
    }
    int lastSerial = sum % 10;
    cout << lastSerial << endl;

    return 0;
}