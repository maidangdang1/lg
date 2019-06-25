#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

struct node
{
    int c;
    int w;
};

int main()
{
    freopen("test.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    node data[n + 10];
    int i;
    for (i = 1;i <= n;i++)
        cin >> data[i].c >> data[i].w;
    int dp[m + 10];
    memset(dp, 0, sizeof(dp));
    int j;
    for (i = 1;i <= n;i++)
    {
        for (j = m;j >= data[i].c;j--)
            dp[j] = max(dp[j], dp[j - data[i].c] + data[i].w);
    }
    cout << dp[m];
    fclose(stdin);
    return 0;
}
