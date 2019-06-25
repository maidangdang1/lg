#include <iostream>
#include <algorithm>

using namespace std;

struct node
{
    int p;
    int t;
};

bool comp(node x, node y)
{
    return x.p < y.p;
}

int main()
{
    int n;
    int k;
    cin >> n >> k;
    node data[k + 10];
    int i;
    for (i = 1;i <= k;i++)
        cin >> data[i].p >> data[i].t;
    sort(data + 1, data + 1 + k, comp);
    int help
}
