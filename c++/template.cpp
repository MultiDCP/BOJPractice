#include <bits/stdc++.h>
using namespace std;

vector<string> split(string str, char delimiter){
    istringstream iss(str);
    string buffer;

    vector<string> result;

    while(getline(iss, buffer, delimiter)){
        result.push_back(buffer);
    }

    return result;
}

/* split 구조
istringstream에 str을 담음
구분자를 기준으로 절삭된 문자열이 담겨짐
istringstream은 istream을 상속받기에 getline을 사용할 수 있다.
getline(입력스트림 오브젝트, 문자열 저장할 객체, 제한자)
해서 일일이 반복해서 delimiter 사이를 가져와 넣어주면 된다
*/

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    

    return 0;
}