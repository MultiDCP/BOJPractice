#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> v1;
vector<int> v2;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i=0; i<n; i++){
        int tmp;
        cin >> tmp;
        v1.push_back(tmp);
        v2.push_back(tmp);
    }
    sort(v2.begin(), v2.end());
    v2.erase(unique(v2.begin(), v2.end()), v2.end());
    for(int i=0; i<n; i++)
        cout << lower_bound(v2.begin(), v2.end(), v1[i]) - v2.begin() << " ";

    return 0;
}

/*
외부의 힌트를 받아서 풀었음. 복습 필요

테크닉 : unique와 lower_bound(이진 탐색)을 통해 시간복잡도를 줄인다.
대부분의 내가 생각했던 풀이는 모두 O(N^2) 풀이들이었다.
하지만 내가 탐색을 할 때 이진탐색을 고려하지 않았기에 그런 결과가 나왔다.
unique 함수를 통해 정렬된 임시 벡터에서 중복값을 걸러내고,
메인 벡터의 값이 임시 벡터의 어디에 위치해있는지 인덱스를 반환받으면 된다.
이 탐색의 과정에서 이진 탐색을 사용할 수 있으며,
lower_bound 함수를 사용해 인덱스도 반환받을 수 있다.
그러면 O(NlgN)으로 시간복잡도를 단축시킬 수 있게 된다.
*/