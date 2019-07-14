#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <cstdio>

using namespace std;

bool ans[1034][1034];
//int a;

void dfs(int s1, int s2, int l1, int l2)
{
    int i;
    int j;
    int mid1 = (s1 + l1) >> 1;
    int mid2 = (s2 + l2) >> 1;
    if (s1 == l1 && s2 == l2)
        return;
    else
    {
        for (i = s1; i <= mid1; i++)
        {
            for (j = s2;j <= mid2;j++)
                ans[i][j] = false;
        }
    }
    dfs(s1, mid2 + 1, mid1, l2);
    dfs(mid1 + 1, s2, l1, mid2);
    dfs(mid1 + 1, mid2 + 1, s2, l2);
}

int main()
{
    int n;
    cin >> n;
    int a = pow(2, n);
    memset(ans, true, sizeof(ans));
    dfs(1, 1, a, a);
    int i;
    int j;
    for (i = 1;i <= a;i++)
    {
        for (j = 1;j <= a;j++)
        {
            if (ans[i][j])
                cout << 1 << " ";
            else
                cout << 0 << " ";
        }
        cout << endl;
    }
    return 0;
}
