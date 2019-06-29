#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <cstdio>

using namespace std;

struct node
{
    int p;
    int t;
};

int main()
{
    freopen("test.txt", "r", stdin);
    int n, k;
    cin >> n >> k;
    //node task[k + 10];
    int i;
    /*
    for (i = 1;i <= k;i++)
        cin >> task[i].p >> task[i].t;
    */
    vector <int> task[n + 10];
    int p, t;
    for (i = 1;i <= k;i++)
    {
        cin >> p >> t;
        task[p].push_back(t);
    }
    int rest[n + 10];
    vector <int>::iterator it;
    memset(rest, 0, sizeof(rest));
    for (i = n;i > 0;i--)
    {
        if (task[i].empty())
            rest[i] = rest[i + 1] + 1;
        else
        {
            for (it = task[i].begin();it != task[i].end();it++)
                rest[i] = max(rest[i], rest[i + *it]);
        }
    }
    cout << rest[1];
    fclose(stdin);
    return 0;
}
