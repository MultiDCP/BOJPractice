#include <bits/stdc++.h>
using namespace std;
string s;
float re, pt, cc, ea, tb, cm, ex, total;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while(cin >> s){
        if(cin.eof() || total == 24) break;
        if(s == "Re")
            re++;
        else if(s == "Pt")
            pt++;
        else if(s == "Cc")
            cc++;
        else if(s == "Ea")
            ea++;
        else if(s == "Tb")
            tb++;
        else if(s == "Cm")
            cm++;
        else if(s == "Ex")
            ex++;
        total++;
        s = "";
    }
    cout << fixed;
    cout.precision(2);
    cout << "Re " << int(re) << " " << re/total << "\n";
    cout << "Pt " << int(pt) << " " << pt/total << "\n";
    cout << "Cc " << int(cc) << " " << cc/total << "\n";
    cout << "Ea " << int(ea) << " " << ea/total << "\n";
    cout << "Tb " << int(tb) << " " << tb/total << "\n";
    cout << "Cm " << int(cm) << " " << cm/total << "\n";
    cout << "Ex " << int(ex) << " " << ex/total << "\n";
    cout << "Total " << int(total) << " " << total/total << "\n";

    return 0;
}