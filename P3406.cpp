#include <iostream>
using namespace std;
struct node
{
	int ticket = 0;
	int card = 0;
};
node cost[100010];
long long travel[100010];
int qzh1[100010];
int qzh2[100010];
long long check[100010];
int main()
{
	freopen("test.txt", "r", stdin);
	int n, m;
	cin >> n >> m;
	int i;
	long long sum = 0;
	int a, b, c;
	for (i = 1;i <= m;i++)
		cin >> travel[i];


	i = 1;
	int j = 2;
	int temp;
	long long temp1;
	long long temp2;
	while(i != m)
	{
		temp1 = travel[i];
		temp2 = travel[j];
		if (temp1 > temp2)
			swap(temp1, temp2);
		check[temp1]++;
		check[temp2]--;
		/*
		for (temp = temp1;temp < temp2;temp++)
			check[temp]++;
		*/
		
		i++;
		j++;
	}
	for (i = 1;i < n;i++)
		check[i] += check[i - 1];

	/*
	for (temp = 1;temp < n;temp++)
		cout << check[temp] << endl;
	cout << endl;
	*/


	for (i = 1;i < n;i++)
	{
		cin >> a >> b >> c;
		temp1 = a * check[i];
		temp2 = b * check[i] + c;
		if (temp1 < temp2)
			sum += temp1;
		else
		{
			if (check[i])
				sum += temp2;
		}
		/*
		if (a < b + c)
			cost[i].ticket = a;
		else
		{
			cost[i].ticket = b;
			cost[i].card = c;
		}
		qzh1[i] = qzh1[i - 1] + cost[i].ticket;
		qzh2[i] = qzh2[i - 1] + cost[i].card;
		*/
	}
	/*
	for (i = 1;i < n;i++)
		cout <<cost[i].ticket << " " << cost[i].card << " " << qzh1[i] << " " << qzh2[i] << endl;
	*/
	/*
	while(i != m)
	{
		temp1 = i;
		temp2 = j;
		if (temp1 > temp2)
			swap(temp1, temp2);
		sum += (qzh1[temp2 - 1] - qzh1[temp1 - 1]);
		sum += (qzh2[temp2 - 1] - qzh2[temp1 - 1]);
		check[temp1]++;
		check[temp2]--;
		i++;
		j++;
	}
	for (i = 1;i < n;i++)
		check[i] += check[i - 1];
	for (i = 1;i < n;i++)
	{
		if (check[i])
			sum -= cost[i].card * (check[i] - 1);
	}
	*/
	cout << sum << endl;
	fclose(stdin);
	return 0;
}