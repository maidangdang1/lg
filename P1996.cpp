#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector <int> ans;
    int i;
    for (i = 1;i <= n;i++)
        ans.push_back(i);
    vector <int> ::iterator it = ans.begin() - 1;
    while (ans.empty() == false)
    {
        for (i = 1;i <= m;i++)
        {
            it++;
            if (it == ans.end())
                it = ans.begin();
        }
        cout << *it << " ";
        ans.erase(it);
        it--;
    }
    return 0;
}
