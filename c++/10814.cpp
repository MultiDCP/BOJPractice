#include <bits/stdc++.h>
using namespace std;

class member{
public:
    int age;
    string name;
    int signIn;
};
bool compare(member a, member b){
    if(a.age == b.age)
        return a.signIn < b.signIn;
    else
        return a.age < b.age;
}
int n;
member myMem[100000];
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i=0; i<n; i++){
        int age; string name;
        cin >> age >> name;
        myMem[i] = member();
        myMem[i].age = age;
        myMem[i].name = name;
        myMem[i].signIn = i;
    }
    sort(myMem, myMem+n, compare);
    for(int i=0; i<n; i++)
        cout << myMem[i].age << " " << myMem[i].name << "\n";
    return 0;
}