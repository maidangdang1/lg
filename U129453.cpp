#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    long long n, k;
    cin >> n >> k;
    if (k == 0)
    {
        cout << n;
        return 0;
    }
    bool seat[n + 10];
    memset(seat, false, sizeof(seat));
    long long ans = 0;
    seat[1] = true;
    ans++;
    long long d;
    long long num;
    long long temp;
    long long temp1;
    long long temp2;
    priority_queue <int, vector<int>, greater<int> > dis;
    temp = 1;
    long long i;
    vector <int> sumseat;
    sumseat.push_back(1);
    while (true)
    {
        d = 0;
        num = n;
        for (i = n;i >= 1;i--)
        {
            if (seat[i])
                continue;
            while (!dis.empty())
                dis.pop();
            for (auto j = sumseat.begin();j != sumseat.end();j++)
            {
                if (i > *j)
                {
                    temp1 = i - *j - 1;
                    temp2 = *j + n - i - 1;
                    if (temp1 >= k && temp2 >= k)
                    {
                        /*
                        if (min(temp1, temp2) > d && i > num)
                        {
                            d = min(temp1, temp2);
                            num = i;
                        }
                        */
                       dis.push(min(temp1, temp2));
                    }
                    else
                    {
                        seat[i] = true;
                        temp++;
                    }
                }
                else
                {
                    temp1 = *j - i - 1;
                    temp2 = i + n - *j - 1;
                    if (temp1 >= k && temp2 >= k)
                    {
                        /*
                        if (min(temp1, temp2) > d && i > num)
                        {
                            d = min(temp1, temp2);
                            num = i;
                        }
                        */
                       dis.push(min(temp1, temp2));
                    }
                    else
                    {
                        seat[i] = true;
                        temp++;
                    }
                }
            }
            if (dis.empty())
                continue;
            if (dis.top() >= d && i < num && seat[i] != true)
            {
                d = dis.top();
                num = i;
            }
        }
        if (temp == n)
            break;
        sumseat.push_back(num);
        seat[num] = true;
        temp++;
    }
    cout << sumseat.size();
    return 0;
}