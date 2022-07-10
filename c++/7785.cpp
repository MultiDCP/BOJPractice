#include <bits/stdc++.h>
using namespace std;
int n;
set<string> m;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i=0; i<n; i++){
        string pName, work;
        cin >> pName >> work;
        if(work == "enter")
            m.insert(pName);
        else if(work == "leave"){
            auto it = m.find(pName);
            if(it != m.end())
                m.erase(it);
        }
    }
    

    auto itr = m.end();
    itr--;
    while(itr != m.begin()){
        cout << *itr << "\n";
        itr--;
    }
    cout << *itr << "\n";

    return 0;
}