#include <iostream>
#include <list>

using namespace std;

int main(void)
{
    list<char> L = {};

    string s;
    cin >> s;

    for (int i = 0; i < s.length(); i++)
    {
        L.push_back(s[i]);
    }

    int repeat;
    cin >> repeat;

    auto k = L.end();
    for (int i = 0; i < repeat; i++)
    {
        char c;
        cin >> c;

        if (c == 'L')
        {
            if (k == L.begin()) continue;
            k--;
        }
        else if (c == 'D')
        {
            if (k == L.end()) continue;
            k++;
        }
        else if (c == 'B')
        {
            if (k == L.begin()) continue;
            k--;
            k = L.erase(k);
        }
        else if (c == 'P')
        {
            char newC;
            cin >> newC;
            L.insert(k, newC);
        }
    }

    for (auto k = L.begin(); k != L.end(); k++)
    {
        cout << *k;
    }
    cout << "\n";
}