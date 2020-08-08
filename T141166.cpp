#include <iostream>
#include <vector>

using namespace std;

int main()
{
    long long n;
    cin >> n;
    long long a[n + 10];
    long long i;
    for (i = 0;i < n;i++)
        cin >> a[i];
    long long q;
    cin >> q;
    long long m;
    for (i = 1;i <= q;i++)
    {
        cin >> m;
        long long s = 0;
        while (m >= 0)
        {
            s = 0;
            for (long long j = 0;j < n;j++)
                s += a[j] ^ m;
            if (s <= m)
            {
                cout << m << endl;
                break;
            }
            m--;
        }
        if (s > m)
            cout << -1 << endl;
    }
    return 0;
}