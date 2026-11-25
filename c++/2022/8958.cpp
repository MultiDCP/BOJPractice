#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> result;

    int n;
    cin >> n;

    for(int i=0; i<n; i++){
        string temp;
        cin >> temp;

        int tempResult = 0;
        int count = 0;
        
        for(int j=0; j<temp.length(); j++){
            if(temp[j] == 'O'){
                tempResult += ++count;
            }
            else{
                count = 0;
            }
        }

        result.push_back(tempResult);
    }

    for(int i=0; i<result.size(); i++){
        cout << result[i] << '\n';
    }
    return 0;
}