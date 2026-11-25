#include <iostream>
#include <vector>
using namespace std;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> a;
    int n, x;
    cin >> n >> x;

    for(int i=0; i<n; i++){
        int tmp;
        cin >> tmp;

        if(tmp < x){
            a.push_back(tmp);
        }
    }

    for(int i=0; i<a.size(); i++){
        cout << a[i] << ' ';
    }
    cout << '\n';

    return 0;
}