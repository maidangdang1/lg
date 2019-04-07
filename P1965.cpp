#include <iostream>

typedef long long ll;

using namespace std;

int main()
{
    freopen("test.txt", "r", stdin);
    ll n, m, k, x;
    cin >> n >> m >> k >> x;
    //int cnt = 0;
    //int i;
    ll temp = 0;
    while (k > 4)
    {
        temp = m * 100000;
        m = temp % n;
        k -= 5;
    }
    while (k--)
    {
        temp = m * 10;
        m = temp % n;
    }
    x += m;
    x %= n;
    cout << x;
    fclose(stdin);
    return 0;
}
