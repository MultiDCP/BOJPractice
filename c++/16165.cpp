#include <bits/stdc++.h>
using namespace std;
int n, m;
multimap<string, string> g;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for(int i=0; i<n; i++){
        string gName;
        int pNum;
        cin >> gName >> pNum;
        vector<string> tmp;
        for(int j=0; j<pNum; j++){
            string pName;
            cin >> pName;
            tmp.push_back(pName);
        }
        sort(tmp.begin(), tmp.end());
        for(int j=0; j<pNum; j++)
            g.insert({gName, tmp[j]});
    }

    for(int i=0; i<m; i++){
        string nm;
        int qNum;
        cin >> nm >> qNum;
        auto j = g.begin();
        if(qNum == 0){
            while(j->first != nm && j != g.end())
                j++;
            while(j->first == nm){
                cout << j->second << "\n";
                j++;
            }
        }
        else{
            while(j->second != nm && j != g.end())
                j++;
            cout << j->first << "\n";
        }
    }

    return 0;
}
