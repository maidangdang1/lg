#include <iostream>

using namespace std;

const unsigned long long mod = 1e9 + 7;

unsigned long long ksm(unsigned long long b, unsigned long long k)
{
    unsigned long long s = 1;
    while (k)
    {
        if (k % 2 == 1)
            s = s * b % mod;
        b = b * b % mod;
        k = k >> 1;
    }
    s = s % mod;
    return s;
}

int main()
{
    int n;
    unsigned long long k;
    cin >> n >> k;
    unsigned long long a[n + 10][n + 10];
    int i, j;
    for (i = 1;i <= n;i++)
    {
        for (j = 1;j <= n;j++)
            cin >> a[i][j];
    }
    for (i = 1;i <= n;i++)
    {
        for (j = 1;j <= n;j++)
            a[i][j] = ksm(a[i][j], k);
    }
    for (i = 1;i <= n;i++)
    {
        for (j = 1;j <= n;j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
    return 0;
}