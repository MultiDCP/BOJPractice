#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int front = 0;

    for(int i=0; i<3; i++){
        for(int j=0; j<4; j++){
            int temp;
            cin >> temp;
            if(temp)
                front++;
        }
        switch(front){
            case 0:
                cout << "D\n";
                break;
            case 1:
                cout << "C\n";
                break;
            case 2:
                cout << "B\n";
                break;
            case 3:
                cout << "A\n";
                break;
            case 4:
                cout << "E\n";
                break;
        }
        front = 0;
    }

    return 0;
}