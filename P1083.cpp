#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>

using namespace std;

const int INF = 1000010;

struct node
{
    int d;
    int s;
    int t;
};

int n, m;
int r[INF];
node order[INF];
int cf[INF];
int copyed[INF];

bool check(int ans)
{
    memset(cf, 0, sizeof(cf));
    memcpy(copyed, r, sizeof(r));
    int i;
    for (i = 1;i <= ans;i++)
    {
        cf[order[i].s] -= order[i].d;
        cf[order[i].t + 1] += order[i].d;
    }
    for (i = 1;i <= n;i++)
    {
        cf[i] += cf[i - 1];
        copyed[i] += cf[i];
        if (copyed[i] < 0)
            return false;
    }
    return true;
}

int main()
{
    freopen("test.txt", "r", stdin);
    //int n, m;
    cin >> n >> m;
    //int r[n + 10];
    int i;
    for (i = 1;i <= n;i++)
        cin >> r[i];
    //node order[n + 10];
    for (i = 1;i <= m;i++)
        cin >> order[i].d >> order[i].s >> order[i].t;
    //int cf[n + 10];
    //int copyed[n + 10];
    //memset(cf, 0, sizeof(cf));
    int l = 1;
    int r = m;
    int mid;
    while (l < r)
    {
        mid = (l + r) >> 1;
        if (check(mid))
            l = mid + 1;
        else
            r = mid;
    }
    if (l == m && check(mid))
        cout << 0;
    else
        cout << -1 << endl << l;
    fclose(stdin);
    return 0;
}
