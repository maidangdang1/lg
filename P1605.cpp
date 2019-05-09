#include <iostream>

using namespace std;

struct node
{
    bool ans = false;
    bool block = false;
};

int n, m, t;
int sx, sy, fx, fy;
node a[15][15];
int cnt = 0;
int help[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
//node block[35]

void dfs(int nowx, int nowy)
{
    if (nowx == fx && nowy == fy)
    {
        cnt++;
        return;
    }
    int i;
    int j;
    for (i = 0;i < 4;i++)
    {
        if (a[nowx + help[i][0]][nowy + help[i][1]].block == false && nowx + help[i][0] <= n && nowy + help[i][1] <= m && nowx + help[i][0] > 0 && nowy + help[i][1] > 0 && a[nowx + help[i][0]][nowy + help[i][1]].ans == false)
        {
            a[nowx + help[i][0]][nowy + help[i][1]].ans = true;
            dfs(nowx + help[i][0], nowy + help[i][1]);
            a[nowx + help[i][0]][nowy + help[i][1]].ans = false;
        }
    }
}

int main()
{
    cin >> n >> m >> t;
    cin >> sx >> sy >> fx >> fy;
    int i;
    int tempx, tempy;
    for (i = 1;i <= t;i++)
    {
        cin >> tempx >> tempy;
        a[tempx][tempy].block = true;
    }
    a[sx][sy].ans = true;
    dfs(sx, sy);
    cout << cnt;
    return 0;
}
