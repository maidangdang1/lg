#include <iostream>
#include <cstring>
#include <string>
#include <queue>

using namespace std;

struct node
{
    string data;
    int time = 0;
};

int main()
{
    freopen("test.txt", "r", stdin);
    node a;
    node b;
    cin >> a.data >> b.data;
    queue <node> q;
    string help[16][2];
    int num = 1;
    while (cin >> help[num][0] >> help[num][1])
        num++;
    node temp1;
    node temp2;
    q.push(a);
    int i;
    while (q.empty() == false)
    {
        temp1 = q.front();
        q.pop();
        if (temp1.data == b.data)
        {
            cout << temp1.time;
            fclose(stdin);
            return 0;
        }
        if (temp1.time > 10)
        {
            cout << "NO ANSWER!";
            fclose(stdin);
            return 0;
        }
        for (i = 1;i < num;i++)
        {
            if (temp1.data.find(help[i][0]))
            {
                temp2.data = temp1.data.replace(temp1.data.find(help[i][0]), help[i][0].length(), help[i][1]);
                temp2.time = temp1.time + 1;
                q.push(temp2);
            }
        }
    }
}