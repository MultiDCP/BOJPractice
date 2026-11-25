#include <bits/stdc++.h>
using namespace std;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string a;
    list<char> l;

    cin >> a;
    for(int i=0; i<a.length(); i++){
        l.push_back(a[i]);
    }

    list<char>::iterator t = l.end();

    int m;
    cin >> m;

    for(int i=0; i<m; i++){
        char order;

        cin >> order;

        if(order == 'L'){
            if(t != l.begin()){
                --t;
            }
        }
        else if(order == 'D'){
            if(t != l.end()){
                ++t;
            }
        }
        else if(order == 'B'){
            if(t != l.begin() && !l.empty()){
                t--;
                t = l.erase(t);
            }
        }
        else if(order == 'P'){  
            char temp;
            cin >> temp;

            l.insert(t, temp);
        }
    }

    for(t=l.begin(); t!=l.end(); t++){
        cout << *t;
    }
    cout << '\n';

    return 0;
}

/*
바로 정답을 맞혔지만 시간이 오래 걸린 이유
1. list의 insert와 erase 메소드의 이해 부족
해당 메소드들을 사용하였을 때,
insert의 경우 iterator의 '왼편'에 값이 삽입되고
iterator는 원래 가리키던 값을 가리키지만,
erase의 경우 iterator가 '가리키고 있는 값'을 지우고
'없어진 값의 오른편'의 값을 가리키게 된다.
이러한 특성들을 몰라서 양옆에 '0'를 집어넣거나
iterator을 깎지 않고 그 자리를 바로 비우는 등의 오류를 범하여
잘못된 메모리에 접근하게 되어 프로그램이 꼬이게 되었다.
이해도가 낮아 이를 고치는 데 시간이 더 소요됐다.
테스트 케이스나 디버그 코드를 더 써봤다면 더 단축됐을수도.
2. 문제 해석능력 부족
커서와 문자가 가리키는 것이 어떤 느낌인지를 바로 그리지 못해
이를 해석하는데에 많은 시간을 썼다.
*/