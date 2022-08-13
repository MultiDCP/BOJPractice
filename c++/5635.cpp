#include <bits/stdc++.h>
using namespace std;
int n;
vector<pair<string, pair<pair<int, int>, int>>> v;
bool compare(pair<string, pair<pair<int, int>, int>> a, pair<string, pair<pair<int, int>, int>> b){
    if(a.second.second == b.second.second)
        if(a.second.first.second == b.second.first.second)
            return a.second.first.first < b.second.first.first;
        else
            return a.second.first.second < b.second.first.second;
    else
        return a.second.second < b.second.second;
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i=0; i<n; i++){
        string name;
        int y, m, d;
        cin >> name >> y >> m >> d;
        v.push_back({name, {{y, m}, d}});
    }
    sort(v.begin(), v.end(), compare);
    cout << v[n-1].first << "\n" << v[0].first << "\n";

    return 0;
}