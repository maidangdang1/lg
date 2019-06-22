#include <iostream>

using namespace std;

struct node
{
    int p;
    int t;
};

int main()
{
    int n;
    int k;
    cin >> n >> k;
    node data[n + 10];
    int i;
    for (i = 1;i <= n;i++)
        cin >> data[i].p >> data[i].t;
    
}
