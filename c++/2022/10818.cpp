#include <iostream>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;

    int max = -1000001;
    int min =  1000001;

    for(int i=0; i<n; i++){
        int tmp;
        cin >> tmp;
        if(tmp > max){
            max = tmp;
        }
        if(tmp < min){
            min = tmp;
        }
    }

    cout << min << ' ' << max << '\n';
    return 0;
}