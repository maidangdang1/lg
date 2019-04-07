#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
struct node
{
	int a;
	int b;
	int g;
	int k;
};
//int dt[1000][1000];
int main()
{
    freopen("test.txt", "r", stdin);
    int n;
    cin >> n;
    node d[n + 1];
    int i;
    //int a, b, g, k;
    int num = 0;
    for (i = 1;i <= n;i++)
    	cin >> d[i].a >> d[i].b >> d[i].g >> d[i].k;
    int x, y;
    cin >> x >> y;
    for (i = 1;i <= n;i++)
    {
    	if (x >= d[i].a && y >= d[i].b && x <= d[i].a + d[i].g && y <= d[i].b + d[i].k)
    		num = i;
	}
	if (num)
		cout << num;
	else
		cout << "-1";
    return 0;
}
