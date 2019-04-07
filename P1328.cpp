#include <iostream>

using namespace std;

int role[6][6];

void init()
{
	int i;
	int j;
	role[0][1] = role[0][4] = role[1][2] = role[1][4] = role[2][3] = -1;
	role[0][2] = role[0][3] = role[1][3] = role[2][4] = role[3][4] = 1;
	role[1][0] = role[4][0] = role[2][1] = role[4][1] = role[3][2] = 1;
	role[2][0] = role[3][0] = role[3][1] = role[4][2] = role[4][3] = -1;
	/*
	for (i = 0;i < 5;i++)
	{
		for (j = 0;j < 5;j++)
			cout << role[i][j] << " ";
		cout << endl;
	}
	*/
}

int main()
{
	freopen("test.txt", "r", stdin);
	int n, na, nb;
	cin >> n >> na >> nb;
	int a[na + 10];
	int b[nb + 10];
	int i;
	for (i = 1;i <= na;i++)
		cin >> a[i];
	for (i = 1;i <= nb;i++)
		cin >> b[i];
	int ascore, bscore;
	ascore = 0;
	bscore = 0;
	int tempa = 1;
	int tempb = 1;
	init();
	int j;
	while (n--)
	{
		if (tempa > na)
			tempa = 1;
		if (tempb > nb)
			tempb = 1;
		if (role[a[tempa]][b[tempb]] == 1)
			ascore++;
		else if (role[a[tempa]][b[tempb]] == -1)
			bscore++;
		tempa++;
		tempb++;
	}
	cout << ascore << " " << bscore;
	fclose(stdin);
	return 0;
}
