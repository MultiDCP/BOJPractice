#include <iostream>

using namespace std;

void insert(int idx, int num, int arr[], int& len);
void erase(int idx, int arr[], int& len);

int main(void)
{
    int arr[10] = {10, 50, 40, 30, 70, 20};
    int len = 6;
    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
    insert(3, 60, arr, len);
    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
    erase(4, arr, len);
    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
    return 0;
}

void insert(int idx, int num, int arr[], int& len)
{
    for (int i = len; i > idx; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[idx] = num;
    len++;
}

void erase(int idx, int arr[], int& len)
{
    for (int i = idx; i < len; i++)
    {
        arr[i] = arr[i + 1];
    }
    len--;
}