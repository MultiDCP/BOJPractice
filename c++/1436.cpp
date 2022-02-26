#include <bits/stdc++.h>
using namespace std;

int arr[10000];
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    int count = 0;
    int temp = 665;
    while(count < 10000){
        string t = to_string(temp);
        size_t p = t.find("666");
        if(p != string::npos){
            arr[count++] = temp;
        }
        ++temp;
    }

    cout << arr[n-1];

    return 0;
}

/*
짤막한 생각
배열에 값을 저장할 필요 없이
그냥 count가 n이 되었을 때
그 때 걍 그 값을 출력하는 식으로 했으면
공간복잡도 측면에서 훨씬 나았을지도
*/