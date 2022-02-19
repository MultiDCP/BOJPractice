#include <iostream>
using namespace std;

int a[10];
int remain[42];

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    for(int i=0; i<10; i++){
        cin >> a[i];
        int tmp = a[i] % 42;
        ++remain[tmp];
    }

    int num = 0;

    for(int i=0; i<42; i++){
        if(remain[i] > 0){
            num++;
        }
    }

    cout << num << '\n';

    return 0;
    
}