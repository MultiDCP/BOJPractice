#include <string>
#include <vector>
#include <iostream>

using namespace std;

int main(void){
    string str;

    getline(cin, str);
    
    for(int i=0; i<str.length(); i++){
        if(str[i] >= 97 || str[i] <= 122){
            str[i] = toupper(str[i]);
        }
    }

    string word;
    vector<int> count;

    for(int i=0; i<str.length(); i++){
        if(word.find(str[i]) == string::npos){
            word.push_back(str[i]);
            count.push_back(1);
        }
        else{
            int index = word.find(str[i]);
            count[index]++;
        }
        str[i] = '0';
    }

    /*
    cout << word << endl;
    for(int i=0; i<count.size(); i++){
        cout << count[i] << ' ';
    }
    cout << endl;
    */

    int max = -1;
    char maxChar;
    vector<char> overlapChar;

    for(int i=0; i<count.size(); i++){
        if(max < int(count[i])){
            max = int(count[i]);
            maxChar = word[i];
            overlapChar.clear();
        }
        else if(max == int(count[i])){
            overlapChar.push_back(word[i]);
        }
    }

    if(overlapChar.size() > 0){
        cout << "?" << endl;
    }
    else{
        cout << maxChar << endl;
    }

    return 0;
}

/*
오답 및 시간이 오래 걸린 이유

1. string, list, vector에 대한 이해도가 부족하였음
- 그 때 그 때 필요한 메소드를 골라 빠르게 사용할 수 있어야 하나
이제 C++을 다시 배운 시점에서 해당 메소드를 자유롭게 사용하기엔 부족하였음

2. 문자의 개수를 임시로 저장하는 컨테이너를 string으로 사용함
- 따라서 문자가 1~9개일 때는 계산이 가능했으나
똑같은 문자가 10개 이상 나올 때는 저장 및 계산이 꼬여버림
(메모리 참조에서 큰 오류가 발생함)

3. 반복문 탈출에서의 실수
word와 count를 모두 계산하고 count를 다시 계산하는 과정에서
중복되는 값이 하나라도 나올 경우 반복문을 탈출하고 그대로 값을 내버림
이 경우 단어의 개수가 각각 5, 4, 5, 6으로 나올 경우
단어 개수가 제일 많은 것은 4번째 6이지만, 코드상으로는 5가 2개 있어
단어가 여러 개 있다는 결론을 내었고 ?를 출력하게 됨
이것이 오답의 직접적인 원인이 되었음

4. 알고리즘을 떠올리는 데에 시간을 많이 허비함
1번과도 연관됨. 해당 컨테이너가 쓸 수 있는 메소드가 무엇인지를 찾아보다가
구현이 어렵거나 복잡하다는 것을 깨달을 때 진도를 더 나가지 못함.
이 과정에서 시간이 많이 허비됨.

*/