#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b, c;

    cin >> a;
    cin >> b;
    cin >> c;

    long long result = a * b * c;
    string text = to_string(result);

    vector<int> v = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    for(int i=0; i<text.length(); i++){
        int tmp = text[i] - '0';
        v[tmp]++;
    }

    for(int i=0; i<v.size(); i++){
        cout << v[i] << endl;
    }

    return 0;
}