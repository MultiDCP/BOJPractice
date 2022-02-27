#include <bits/stdc++.h>
using namespace std;

vector<int> v;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n;

    for(int i=0; i<n; i++){
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());

    cin >> m;
    for(int i=0; i<m; i++){
        int num;
        cin >> num;

        bool isFind = false;
        
        int start = 0;
        int final = v.size()-1;

        while(start <= final){
            int mid = (start + final) / 2;
            if(num == v[mid]){
                isFind = true;
                break;
            }
            else if(num > v[mid]){
                start = mid + 1;
            }
            else{
                final = mid - 1;
            }
        }

        if(isFind){
            cout << "1\n";
        }
        else{
            cout << "0\n";
        }

    }

    return 0;
}

/*
런타임 에러가 발생했던 이유
start와 final의 값으로는 인덱스를 넣어줬어야 했다.
그런데 내가 front와 back의 값을 넣어버렸다
일례로 1 2 4 8 16 32 같은 게 나오면
(start + final) / 2 는 16이 나오는데 이를 인덱스에다 집어넣으면
반드시 오류가 날 수밖에 없다
이진탐색 만질 때 이런 점에 유의하자
또한 이진탐색 알고리즘도 정확하게 명시해두자
*/