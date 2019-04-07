#include <iostream>
using namespace std;
struct node
{
	int head = 0;
	int next = 0;
};
int main()
{
	freopen("test.txt", "r", stdin);
	//freopen("try.txt", "w", stdout);
	int n;
	cin >> n;
	int i;
	int temp;
	int k;
	int first = 1;
	int p;
	int o;
	int cou = 1;
	node a[n + 1];
	a[1].head = a[1].next = 1;
	for (i = 2;i <= n;i++)
	{
		cin >> k >> p;
		if (p)
		{
			if (a[k].next != k)
			{
				a[i].next = a[k].next;
				a[k].next = i;
				a[i].head = k;
				a[a[i].next].head = i;
			}
			else
			{
				a[k].next = i;
				a[i].head = k;
				a[i].next = i;
			}
		}
		else
		{
			if (a[k].head != k)
			{
				a[i].next = k;
				a[a[k].head].next = i;
				a[i].head = a[k].head;
				a[k].head = i;
			}
			else
			{
				a[k].head = i;
				a[i].next = k;
				a[i].head = i;
				first = i;
			}
		}
		/*
		for (o = 1;o <= 4;o++)
			cout << a[o].head << " ";
		cout << endl;
		for (o = 1;o <= n;o++)
			cout << a[o].next << " ";
		cout << first;
		cout << endl << endl;
		o = first;
		cout << o << " ";
		while (a[o].next != o)
		{
			o = a[o].next;
			cout << o << " ";
		}
		cout << endl;
		*/
	}
	//cout << endl;
	//cout << first << endl;
	/*
	while (a[first].next != first)
	{
		cout << first << " ";
		first = a[first].next;
	}
	cout << endl;
	*/
	//cout << a[692].next << " " << a[698].head << " " << a[698].next << " " << a[794].head << " " << a[794].next << " " << a[615].head << endl;
	int m;
	cin >> m;
	int x;
	for (i = 1;i <= m;i++)
	{
		cin >> x;
		if (a[x].head == 0)
			continue;
		else if (x == first)
		{
			first = a[x].next;
			a[x].head = a[x].next = 0;
		}
		else if (a[x].next == x)
		{
			a[a[x].head].next = a[x].head;
			a[x].head = a[x].next = 0;
		}
		else
		{
			a[a[x].head].next = a[x].next;
			a[a[x].next].head = a[x].head;
			a[x].head = a[x].next = 0;
		}
		/*
		cout << cou << ": " << a[692].next << " " << a[698].head << " " << a[698].next << " " << a[794].head << " " << a[794].next << " " << a[615].head << endl;
		cou++;
		*/
	}
	/*
	cout << first << endl;
	cout << a[first].next << endl;
	*/
	cout << first << " ";
	while (a[first].next != first)
	{
		first = a[first].next;
		cout << first << " ";
	}
	cout << endl;
	//fclose(stdout);
	fclose(stdin);
	return 0;
}