#include <bits/stdc++.h>
using namespace std;
int l, c;
vector<char> v;
vector<int> tmp;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> l >> c;
    for(int i=0; i<c; i++){
        char w;
        cin >> w;
        v.push_back(w);
        if(i < l)
            tmp.push_back(1);
        else
            tmp.push_back(0);
    }

    sort(v.begin(), v.end());

    do{
        string s;
        for(int i=0; i<v.size(); i++){
            if(tmp[i] == 1)
                s.push_back(v[i]);
        }
        int vowel = 0;
        int conso = 0;
        for(int i=0; i<s.length(); i++){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
                vowel++;
            else
                conso++;
        }
        if(conso >= 2 && vowel >= 1)
            cout << s << "\n";
    } while(prev_permutation(tmp.begin(), tmp.end()));

    return 0;
}

/*
prev_permutation에 대한 문법을 참고하며 풀었음. 복습 필요.
*/