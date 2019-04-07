#include <iostream>

typedef long long ll;

using namespace std;

ll a[1010];

int dfs(int n)
{
    int num = 0;
    if (n == 1 || n == 0)
        return 1;
    else
    {
        int i;
        for (i = 1;i <= n / 2;i++)
        {
            if (a[i])
                num += a[i];
            else
            {
                num += dfs(i);
            }
        }
    }
    num++;
    a[n] = num;
    return num;
}

int main()
{
    freopen("test.txt", "r", stdin);
    int n;
    cin >> n;
    a[0] = 1;
    a[1] = 1;
    int cnt = dfs(n);
    cout << cnt;
    fclose(stdin);
    return 0;
}
