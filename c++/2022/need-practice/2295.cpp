#include <bits/stdc++.h>
using namespace std;
int n, d;
int a[1000];
vector<int> v;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i=0; i<n; i++)
        cin >> a[i];
    sort(a, a+n);

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            d = a[i] + a[j];
            v.push_back(d);
        }
    }
    sort(v.begin(), v.end());
    int tmp;
    for(int i=n-1; i>=0; i--)
        for(int j=0; j<i; j++)
            if(binary_search(v.begin(), v.end(), a[i]-a[j])){
                cout << a[i];
                return 0;
            }

    return 0;
}

/*
오답 정리
이건 복습 무조건 해야겠다
난 왜 이분탐색을 진짜 더럽게 못하는 걸까

1. 문제 이해 자체가 글러먹었다
아무 수나 중복으로 골라서 하면 되는 거를 연속한 세 수를 쳐찾고 있었다
2003번 문제 풀다가 논리 회로가 꼬여서 똑같이 생각한 거 같다
2. 코드 근본이나 접근 방식이나 다 글러먹었다
a + b + c = d 면 a + b = d - c를 만족하는 애를 찾아도 된다
그러면 O(N^3)에서 O(N^2)로 줄어드니깐
근데 이 방식을 풀이를 기어이 보고나서야 깨달았고
접근도 괴상하게 하면서 틀린 코드를 자꾸 제출하고 있으니
오답이 계속 나올 수밖에 없다
그리고 이분 탐색을 바로 굴리면 되는 것을 인덱스 찾아서 해결하겠다고
그러다가 Meet in the middle 써보겠다고
같잖은 생지랄을 하고 있었다
3. 뇌와 눈이 일을 안한다
몸이 말을 안 듣는데 내가 뭘 어떻게 해야한단 말인가
*/