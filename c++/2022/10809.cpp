#include <iostream>
#include <string>
using namespace std;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int r[26];
    for(int i=0; i<26; i++){
        r[i] = -1;
    }

    string temp;
    cin >> temp;

    for(int i=0; i<temp.length(); i++){
        if(r[temp[i] - 'a'] == -1){   
            r[temp[i] - 'a'] = i;
        }
    }

    for(int i=0; i<26; i++){
        cout << r[i] << " ";
    }
    cout << '\n';
    return 0;
}