#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>

using namespace std;

int main()
{
    freopen("test.txt", "r", stdin);
    string num[21] = {"00", "01", "04", "09", "16", "25", "36", "49", "64", "81", "00", "21", "44", "69", "96", "25", "56", "79", "24", "61", "00"};
    string en[21] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty"};
    string ans[6];
    int i;
    int j;
    string temp;
    string s;
    int len;
    int cnt = 0;
    for (i = 1;i <= 6;i++)
    {
        /*
        cin >> temp;
        len = temp.length();
        if (temp[len - 1] == '.')
            s = strncpy(temp, 0, len - 1);
        else
            s = temp;
        */
       cin >> s;
        for (j = 0;j < 21;j++)
        {
            if (s == en[j])
            {
                ans[cnt] = num[j];
                cnt++;
            }
        }
    }
    bool fir = false;
    for (i = 1;i < cnt;i++)
    {
        for (j = 0;j < cnt - i;j++)
        {
            if (ans[j] + ans[j + 1] > ans[j + 1] + ans[j])
            {
                temp = ans[j];
                ans[j] = ans[j + 1];
                ans[j + 1] = temp;
            }
        }
    }
    temp.clear();
    for (i = 0;i < cnt;i++)
        temp += ans[i];
    i = 0;
    while(temp[i] == '0')
    {
        i++;
    }
    len = temp.length();
    for (i;i < len;i++)
        cout << temp[i];
    fclose(stdin);
    return 0;
}
