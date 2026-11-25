#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(void)
{
    while(true)
    {
        string s;
        getline(cin, s);
        if (s == ".") break;

        stack<char> p;

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(') p.push('(');
            else if (s[i] == '[') p.push('[');
            else if (s[i] == ')')
            {
                if (!p.empty() && p.top() == '(') p.pop();
                else p.push(')');
            }
            else if (s[i] == ']')
            {
                if (!p.empty() && p.top() == '[') p.pop();
                else p.push(']');
            }
        }

        if (p.empty()) cout << "yes\n";
        else cout << "no\n";
    }
    return 0;
}