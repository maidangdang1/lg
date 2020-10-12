#include <iostream>

using namespace std;

int main()
{
    int a, b, c, d, e, f, g, h, i;
    cin >> a >> b >> c >> d >> e >> f >> g >> h >> i;
    int ans = 50 + a + b + c + d + e + f + g;
    if (h)
        ans += 5;
    if (ans >= i)
        cout << "AKIOI";
    else
        cout << "AFO";
    return 0; 
}