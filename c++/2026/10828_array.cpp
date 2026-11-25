#include <iostream>

using namespace std;

int s[10000];
int top = 0;

int main(void)
{
    int repeat;
    cin >> repeat;

    for (int i = 0; i < repeat; i++)
    {
        string order;
        cin >> order;

        if (order == "top")
        {
            if (top == 0) cout << -1 << "\n";
            else cout << s[top-1] << "\n";
        }
        else if (order == "size")
        {
            cout << top << "\n";
        }
        else if (order == "empty")
        {
            if (top == 0) cout << 1 << "\n";
            else cout << 0 << "\n";
        }
        else if (order == "push")
        {
            int newI;
            cin >> newI;
            s[top] = newI;
            top++;
        }
        else if (order == "pop")
        {
            if (top == 0) cout << -1 << "\n";
            else
            {
                cout << s[top-1] << "\n";
                top--;
            }
        }
    }
    return 0;
}