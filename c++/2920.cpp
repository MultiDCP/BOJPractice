#include <iostream>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    char a[8];

    for(int i=0; i<8; i++){
        cin >> a[i];
    }

    if(a[0] == '1'){
        for(int i=0; i<7; i++){
            if(a[i+1] - a[i] != 1){
                cout << "mixed" << '\n';
                return 0;
            }
        }
        cout << "ascending" << '\n';
    }
    else if(a[0] == '8'){
        for(int i=0; i<7; i++){
            if(a[i] - a[i+1] != 1){
                cout << "mixed" << '\n';
                return 0;
            }
        }
        cout << "descending" << '\n';
    }
    else{
        cout << "mixed" << '\n';
    }

    return 0;
}