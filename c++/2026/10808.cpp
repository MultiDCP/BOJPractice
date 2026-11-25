// 알파벳 개수 - 브론즈 4
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(void)
{
    string s;
    cin >> s;

    int arr[26];
    fill(arr, arr+26, 0);

    for (int i = 0; i < s.length(); i++)
    {
        arr[s[i]-'a']++;
    }
    for (int i = 0; i < 26; i++)
    {
        cout << arr[i] << " ";
    }
    cout << " ";
    return 0;
}