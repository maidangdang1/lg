#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int main()
{
    long long n, k;
    cin >> n >> k;
    if (k == 0)
    {
        cout << n;
        return 0;
    }
    bool seat[n + 10];
    memset(seat, false, sizeof(seat));
    long long ans = 0;
    seat[1] = true;
    ans++;
    double temp = n / 2.0;
    while (true)
    {
        
    }
}