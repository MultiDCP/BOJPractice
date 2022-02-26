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
        
        int start = v.front();
        int final = v.back();

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
이진 탐색 맞다
근데 왜 틀리는 거지
*/