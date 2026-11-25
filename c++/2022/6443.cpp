#include <bits/stdc++.h>
using namespace std;
int n;
string tmp;
/*
bool isUsed[20];
vector<string> v;
void recur(string s, int origLength, int curLength){
    if(curLength == origLength){
        v.push_back(s);
        v.erase(unique(v.begin(), v.end()), v.end());
    }
    else{
        for(int i=0; i<origLength; i++){
            if(isUsed[i]) continue;
            s += tmp[i];
            isUsed[i] = 1;
            recur(s, origLength, curLength+1);
            s.pop_back();
            isUsed[i] = 0;
        }
    }
}
*/
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i=0; i<n; i++){
        cin >> tmp;/*
        recur("", tmp.length(), 0);
        sort(v.begin(), v.end());
        for(int j=0; j<v.size(); j++)
            cout << v[j] << "\n";
        v.clear();
        memset(isUsed, 0, sizeof(isUsed));*/
        sort(tmp.begin(), tmp.end());
        do{
            cout << tmp << "\n";
        } while(next_permutation(tmp.begin(), tmp.end()));
    }

    return 0;
}

/*
오답 정리
억울함의 정도가 넘어서면 오히려 허탈하다는 걸 보여준 문제
STL을 애용합시다
*/