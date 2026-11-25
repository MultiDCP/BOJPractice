#include <iostream>

using namespace std;

int q[10000];
int head = 0, tail = 0;

int main(void)
{
    int repeat;
    cin >> repeat;

    for (int i = 0; i < repeat; i++)
    {
        string order;
        cin >> order;

        if (order == "front")
        {
            if (head == tail) cout << -1 << "\n";
            else cout << q[head] << "\n";
        }
        else if (order == "back")
        {
            if (head == tail) cout << -1 << "\n";
            else cout << q[tail - 1] << "\n";
        }
        else if (order == "size")
        {
            cout << tail - head << "\n";
        }
        else if (order == "empty")
        {
            if (head == tail) cout << 1 << "\n";
            else cout << 0 << "\n";
        }
        else if (order == "push")
        {
            int newI;
            cin >> newI;
            q[tail] = newI;
            tail++;
        }
        else if (order == "pop")
        {
            if (head == tail) cout << -1 << "\n";
            else
            {
                cout << q[head] << "\n";
                head++;
            }
        }
    }
    return 0;
}