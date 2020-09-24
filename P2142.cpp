#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <stack>
#include <queue>

using namespace std;

int main()
{
    string temp1, temp2;
    cin >> temp1 >> temp2;
    int i;
    int a[10086 + 10];
    int b[10086 + 10];
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    int len1 = temp1.length();
    int len2 = temp2.length();
    stack <int> ans;
    if (len2 > len1)
    {
        swap(temp1, temp2);
        swap(len1, len2);
        cout << "-";
    }
    else if (len1 == len2)
    {
        if (temp2 > temp1)
        {
            swap(temp1, temp2);
            swap(len1, len2);
            cout << "-";
        }
    }
    int j;
    j = 10085;
    for (i = len1 - 1;i >= 0;i--)
    {
        a[j] = temp1[i] - 48;
        j--;
    }
    j = 10085;
    for (i = len2 - 1;i >= 0;i--)
    {
        b[j] = temp2[i] - 48;
        j--;
    }
    for (i = 10085;i >= 0;i--)
    {
        if (a[i] < b[i])
        {
            a[i] += 10;
            a[i - 1] -= 1;
        }
        ans.push(a[i] - b[i]);
    }
    while (ans.top() == 0)
        ans.pop();
    while (!ans.empty())
    {
        cout << ans.top();
        ans.pop();
    }
    return 0;
}