#include <iostream>

using namespace std;

int main()
{
    //freopen("test.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    int r[n + 10];
    int i;
    for (i = 1;i <= n;i++)
        cin >> r[i];
    int d, s, t;
    int j;
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
    //fclose(stdin);
    return 0;
}