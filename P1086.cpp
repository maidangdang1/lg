#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

struct node
{
    int data;
    int x;
    int y;
};

bool comp(node x, node y)
{
    return x.data > y.data;
}

int main()
{
    freopen("test.txt", "r", stdin);
    int m, n, k;
    cin >> m >> n >> k;
    int i;
    int j;
    //int a[m + 10][n + 10];
    node a[m * n + 10];
    int cnt = 0;
    int temp;
    for (i = 1;i <= m;i++)
    {
        for (j = 1;j <= n;j++)
        {
            cin >> temp;
            if (temp)
            {
                a[cnt].data = temp;
                a[cnt].x = i;
                a[cnt].y = j;
                cnt++;
            }
        }
    }
    sort(a, a + cnt, comp);
    //cnt = 0;
    int num = 0;
    for (i = 0;i < cnt;i++)
    {
        if (i == 0)
        {
            if (a[i].x * 2 + 1 > k)
            {
                cout << 0;
                return 0;
            }
            else
            {
                num += a[i].data;
                k -= a[i].x;
                k--;
            }
        }
        else
        {
            if (abs(a[i].x - a[i - 1].x) + abs(a[i].y - a[i - 1].y) + 1 + a[i].x <= k)
            {
                num += a[i].data;
                k -= abs(a[i].x - a[i - 1].x) + abs(a[i].y - a[i - 1].y);
                k--;
            }
            else
                break;
        }
    }
    cout << num;
    fclose(stdin);
    return 0;
}
