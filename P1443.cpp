//#pragma GCC optimize(3)
#include <iostream>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <iomanip>

using namespace std;

struct node
{
    int data = 0;
    bool used = false;
};

int main()
{
    freopen("test.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    int x, y;
    cin >> x >> y;
    queue <int> q;
    node a[n + 10][m + 10];
    q.push(x);
    q.push(y);
    int temp1;
    int temp2;
    int nowx;
    int nowy;
    int help[8][2] = {{-2, -1}, {2, -1}, {-2, 1}, {2, 1}, {-1, -2}, {1, -2}, {-1, 2}, {1, 2}};
    int i;
    a[x][y].used = true;
    while (q.empty() == false)
    {
        temp1 = q.front();
        q.pop();
        temp2 = q.front();
        q.pop();
        /*
        if (a[temp1][temp2].used == true || temp1 <= 0 || temp1 > n || temp2 <= 0 || temp2 > m)
            continue;
        */
        for (i = 0;i < 8;i++)
        {
            nowx = temp1 + help[i][0];
            nowy = temp2 + help[i][1];
            if (a[nowx][nowy].used == true)
                continue;
            if (nowx <= 0 || nowx > n || nowy <= 0 || nowy > m)
                ;
            else
            {
                q.push(nowx);
                q.push(nowy);
                a[nowx][nowy].data = a[temp1][temp2].data + 1;
                a[nowx][nowy].used = true;
            }
        }
    }
    int j;
    for (i = 1;i <= n;i++)
    {
        for (j = 1;j <= m;j++)
        {
            if (a[i][j].used == false)
                cout << left << setw(5) << -1;
            else
                cout << left << setw(5) << a[i][j].data;
        }
        cout << endl;
    }
    fclose(stdin);
    return 0;
}
