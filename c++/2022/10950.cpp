#include <iostream>
#include <vector>
using namespace std;
int main(void){
    int t;
    vector<int> v;
    cin >> t;

    for(int i=0; i<t; i++){
        int a, b;
        cin >> a >> b;
        v.push_back(a+b);
    }

    for(int i=0; i<v.size(); i++){
        cout << v[i] << '\n';
    }
    return 0;
}