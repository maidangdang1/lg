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
    int help[8][2] = {{-2, -1}, {2, -1}, {-2, 1}, {2, 1}, {-1, -2}, {1, -2}, {-1, 2}, {1, 2}};
    int i;
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
        a[temp1][temp2].used = true;
        for (i = 0;i < 8;i++)
        {
            if (a[temp1 + help[i][0]][temp2 + help[i][1]].used == true || temp1 + help[i][0] <= 0 || temp1 + help[i][0] > n || temp2 + help[i][1] <= 0 || temp2 + help[i][1] > m)
            q.push(temp1 + help[i][0]);
            q.push(temp2 + help[i][1]);
            a[temp1 + help[i][0]][temp2 + help[i][1]].data = a[temp1][temp2].data + 1;
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
    }
    fclose(stdin);
    return 0;
}
