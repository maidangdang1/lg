#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int w[n + 10][m + 10];
    long long a[n + 10][m + 10];
    memset(a, 0, sizeof(a));
    int i;
    int j;
    int k, l;
    for (i = 1;i <= n;i++)
    {
        for (j = 1;j <= m;j++)
            cin >> w[i][j];
    }
    for (i = 1;i <= n;i++)
    {
        for (j = 1;j <= m;j++)
            a[i][j] = max(a[i - 1][j], a[i][j - 1]) + w[i][j];
    }
    int temp;
    long long ans = a[n][m];
    for (i = 1;i <= n;i++)
    {
        for (j = 1;j <= m;j++)
        {
            temp = w[i][j];
            w[i][j] = 0;
            for (k = i;k <= n;k++)
            {
                for (l = j;l <= m;l++)
                    a[k][l] = max(a[k - 1][l], a[k][l - 1]) + w[k][l];
            }
            if (a[n][m] < ans)
                ans = a[n][m];
            w[i][j] = temp;
        }
    }
    cout << ans;
    return 0;
}