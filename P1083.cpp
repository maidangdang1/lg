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
int copy[INF];

bool check(int ans)
{
    memset(cf, 0, sizeof(cf));
    memcpy(copy, r, sizeof(copy));
    int i;
    for (i = 1;i <= ans;i++)
    {
        cf[order[i].s] -= order[i].d;
        cf[order[i].t + 1] += order[i].d;
    }
    for (i = 1;i <= n;i++)
    {
        cf[i] += cf[i - 1];
        copy[i] += cf[i];
        if (copy[i] < 0)
            return false;
    }
    return true;
}

int main()
{
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
    //int copy[n + 10];
    //memset(cf, 0, sizeof(cf));
    int l = 1;
    int r = m;
    int mid;
    while (l < r)
    {
        mid = (l + r) >> 1;
        if (check())
    }
}
