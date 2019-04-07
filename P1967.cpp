#include <iostream>

using namespace std;

struct node
{
    int data;
    bool lt;
};


int main()
{
    int n, m;
    cin >> n >> m;
    node a[n + 10][n + 10];
    int i;
    int x, y, z;
    for (i = 1;i <= m;i++)
    {
        cin >> x >> y >> z;
        a[x][y].lt = true;
        a[x][y].data = z;
        a[y][x].lt = true;
        a[y][x].data = z;
    }
}