#include <bits/stdc++.h>
using namespace std;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<string> v;
    int n;
    cin >> n;

    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        v.push_back(s);
    }

    for(int i=0; i<v.size(); i++){
        for(int j=1+i; j<v.size(); j++){
            if(v[i].length() > v[j].length()){
                v[i].swap(v[j]);
            }
            else if(v[i].length() == v[j].length()){
                if(v[i] > v[j]){
                    v[i].swap(v[j]);
                }
                else if(v[i] == v[j])
                    v.erase(v.begin()+i);
            }
        }
    }

    for(int i=0; i<v.size(); i++){
        cout << v[i] << '\n';
    }

    return 0;
}

/*
오답 정리
STL Sort를 사용하고 그 후 비교를 때리면 되는 문제였다.
헌데, compare을 잘 활용해야 풀 수 있는 문제였다.
이 거지같은 시간 제한을 극복하려면 결국 퀵 소트 등의 빠른 정렬을 쓰거나
그거 까먹었으면 STL을 써야하는 점을 보면
STL을 얼마나 잘 활용하는지 묻는 문제같다
이 STL을 제대로 쓰지 못한 점이 내 패인이었다.
-> STL 공부 제대로 해야할듯...
*/