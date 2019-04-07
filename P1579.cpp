#include <iostream>
#include <cstring>
#include <cstdio>
#include <set>

using namespace std;

int prime[20000];
bool isprime[20000];
int cnt = 1;
set <int> test;
set <int>::iterator it;

void init()
{
	int i;
	int j;
	for (i = 2;i < 20000;i++)
	{
		if (isprime[i])
		{
			prime[cnt] = i;
			test.insert(i);
			cnt++;
			j = i * 2;
			for (j;j < 20000;j += i)
				isprime[j] = false;
		}
	}
}

int main()
{
	int n;
	cin >> n;
	memset(isprime, true, sizeof(isprime));
	init();
	int i;
	int j;
	int temp;
	for (i = 1;i < cnt;i++)
	{
		for (j = i;j < cnt;j++)
		{
			temp = n - prime[i] - prime[j];
			it = test.find(temp);
			if (it != test.end())
			{
				cout << prime[i] << " " << prime[j] << " " << temp;
				return 0;
			}
		}
	}
	/*
	for (i = 1;i < cnt;i++)
		cout << prime[i] << endl;
	*/
	return 0;
}
