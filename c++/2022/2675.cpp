#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    vector<int> r;
    vector<string> str;

    cin >> t;

    for(int i=0; i<t; i++){
        int tmpInt;
        string tmpStr;
        cin >> tmpInt;
        r.push_back(tmpInt);

        cin >> tmpStr;
        str.push_back(tmpStr);
    }
    
    for(int i=0; i<t; i++){
        string tmp = str[i];
        int cycle = r[i];
        
        for(int j=0; j<tmp.length(); j++){
            for(int k=0; k<cycle; k++){
                cout << tmp[j];
            }
        }
        cout << endl;
    }

    return 0;

}