#include <iostream>

using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int num;

    int max = -1;
    int maxIndex = 0;

    for(int i=0; i<9; i++){
        cin >> num;
        if(max < num){
            max = num;
            maxIndex = i+1;
        }
    }

    cout << max << endl;
    cout << maxIndex << endl;

    return 0;
}