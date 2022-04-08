#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n;
double avg;
vector<int> v;
vector<int> lot;
int cnt[8001];
int cntMax = -4001;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i=0; i<n; i++){
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    for(int i=0; i<n; i++){
        avg += v[i];
        cnt[v[i]+4000]++;
    }
    if(round(avg / n) == -0)
        cout << 0 << "\n";
    else
        cout << round(avg / n) << "\n";
    cout << v[n/2] << "\n";
    for(int i=0; i<n; i++){
        if(cntMax == -4001 || cntMax != v[i] && cnt[cntMax+4000] < cnt[v[i]+4000]){
            while(!lot.empty())
                lot.pop_back();
            lot.push_back(v[i]);
            cntMax = v[i];
        }
        else if(cntMax != v[i] && cnt[cntMax+4000] == cnt[v[i]+4000]){
            lot.push_back(v[i]);
            cntMax = v[i];
        }
    }
    if(lot.size() == 1)
        cout << cntMax << "\n";
    else
        cout << lot[1] << "\n";
    cout << v.back() - v.front();

    return 0;
}