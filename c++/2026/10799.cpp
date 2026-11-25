#include <iostream>
#include <stack>

using namespace std;

stack<char> s;
bool isLaserEnable = false;
int sum = 0;

int main(void)
{
    string code;
    cin >> code;
    for (int i = 0; i < code.length(); i++)
    {
        if (code[i] == '(')
        {
            s.push('(');
            isLaserEnable = true;
        }
        else if (code[i] == ')')
        {
            if (isLaserEnable)
            {
                s.pop();
                sum += s.size();
                isLaserEnable = false;
            }
            else
            {
                s.pop();
                sum += 1;
            }
        }
    }
    cout << sum << "\n";
}