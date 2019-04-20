#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>

using namespace std;

struct node
{
    int d;
    int s;
    int t;
};


int main()
{
    freopen("test.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    int r[n + 10];
    int b[n + 10];
    int cf[n + 10];
    memset(cf, 0, sizeof(cf));
    node a[m + 10];
    int i;
    for (i = 1;i <= n;i++)
        cin >> r[i];
    r[0] = r[1];
    int d, s, t;
    int j;
    /*
    for (i = 1;i <= m;i++)
    {
        cin >> d >> s >> t;
        for (j = s;j <= t;j++)
        {
            r[j] -= d;
            if (r[j] < 0)
            {
                cout << -1 << endl;
                cout << i;
                //fclose(stdin);
                return 0;
            }
        }
    }
    cout << 0;
    */
    for (i = 1;i <= m;i++)
        cin >> a[i].d >> a[i].s >> a[i].t;
    //int j;
    bool pd = true;
    for (i = m;i > 0;i--)
    {
        memset(cf, 0, sizeof(cf));
        pd = true;
        for (j = 1;j <= i;j++)
        {
            cf[a[j].s] -= a[j].d;
            cf[a[j].t + 1] += a[j].d;
        }
        for (j = 1;j <= m;j++)
        {
            b[j] = r[j];
            cf[j] += cf[j - 1];
            b[j] += cf[j];
            /*
            if (b[j] < 0)
            {
                cout << -1 << endl;
                cout << i;
                fclose(stdin);
                return 0;
            }
            */
        }
        for (j = 1;j <= m;j++)
        {
            if (b[j] < 0)
                pd = false;
        }
        if (pd)
        {
            if (i == m)
            {
                cout << 0;
                fclose(stdin);
                return 0;
            }
            else
            {
                cout << -1 << endl;
                cout << i + 1;
                fclose(stdin);
                return 0;
            }
        }
        /*
        if (i == m)
        {
            cout << 0;
            fclose(stdin);
            return 0;
        }
        for (j = 1;j <= m;j++)
            cf[j] += cf[j - 1];
        */
    }
    //fclose(stdin);
    return 0;
}
