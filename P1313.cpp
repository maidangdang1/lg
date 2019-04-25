#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>

using namespace std;

const int mod = 10007;

int qpow(int x, int y)
{
    if (y == 0)
        return 1;
    if (x == 0)
        return 0;
    int cnt = 1;
    while (y > 0)
    {
        x %= mod;
        if (y % 2 == 1)
            cnt *= x;
        cnt %= mod;
        x = x * x;
        y = y >> 1;
    }
    return cnt;
}

int main()
{
    freopen("test.txt", "r", stdin);
    int a, b, k, n, m;
    cin >> a >> b >> k >> n >> m;
    if (k == 0)
    {
        cout << 1;
        return 0;
    }
    int c[k + 10];
    int d[k + 10];
    memset(c, 0, sizeof(c));
    c[0] = 1;
    c[1] = 1;
    int i;
    int j;
    for (i = 2;i <= k;i++)
    {
        d[0] = 1;
        d[i] = 1;
        for (j = 1;j < i;j++)
            d[j] = (c[j] + c[j - 1]) % mod;
        memcpy(c, d, sizeof(d));
    }
    int temp1 = qpow(a, n);
    int temp2 = qpow(b, m);
    unsigned long long ans = temp1 * temp2 * c[n];
    ans %= mod;
    cout << ans;
    fclose(stdin);
    return 0;
}