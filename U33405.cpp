#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
multiset<int> b;
struct node
{
    int data;
    bool pd;
};
bool comp(node x, node y)
{
    return x.data < y.data;
}
void xuanze()
{
    
}
int main()
{
    int n, r;
    cin >> n >> r;
    int i;
    node a[n + 1];
    for (i = 1;i <= n;i++)
    {
        cin >> a[i].data;
        b.insert(a[i].data);
    }
    sort(a + 1, a + 1 + n, comp);
    int sum;
    for (i = 1;i <= n;i++)
        sum += a[i];
    int begin = a[n];
    int end = sum;
    int count = 0;
    for (i = begin;i <= end;i++)
    {
        xuanze(i);
    }
}