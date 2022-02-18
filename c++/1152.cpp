#include <string>
#include <iostream>
using namespace std;

int main(void){
    string str;

    getline(cin, str);

    int count = 0;

    for(int i=0; i<str.length(); i++){
        if(str[i] == ' '){
            if(i == 0 || i == str.length() - 1){
                continue;
            }
            count++;
        }
    }
    if(str != " "){
        count++;
    }

    cout << count << endl;

    return 0;
}

/*
오답 이유
1. 문자열이 공백 하나로만 구성되어 있는 경우를 고려하지 못하였음
*/