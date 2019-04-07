#include <iostream>

using namespace std;

struct node
{
    int data;
    int rank;
};


int main()
{
    freopen("test.txt", "r", stdin);
    int n;
    cin >> n;
    int h[n + 10];
    int i;
    for (i = 1;i <= n;i++)
        cin >> h[i];
    bool up = false;
    int cnt = 1;
    for (i = 1;i <= n;i++)
    {
        if (i == n)
            break;
        if (up)
        {
            if (h[i] > h[i + 1])
            {
                cnt++;
                up = !up;
            }
        }
        else
        {
            if (h[i] < h[i + 1])
            {
                cnt++;
                up = !up;
            }
        }
    }
    int maxi = cnt;
    cnt = 1;
    up = true;
    for (i = 1;i <= n;i++)
    {
        if (i == n)
            break;
        if (up)
        {
            if (h[i] > h[i + 1])
            {
                cnt++;
                up = !up;
            }
        }
        else
        {
            if (h[i] < h[i + 1])
            {
                cnt++;
                up = !up;
            }
        }
    }
    if (cnt > maxi)
        cout << cnt;
    else
        cout << maxi;
    fclose(stdin);
    return 0;
}