#include<iostream>
using namespace std;

int n;
int lc[28];
int rc[28];
//int p[28];

void preOrder(int cur)
{
	cout << char(cur + 'A' - 1);
	if(lc[cur]) preOrder(lc[cur]);
	if(rc[cur]) preOrder(rc[cur]);
}

void inOrder(int cur)
{
	if(lc[cur]) inOrder(lc[cur]);
	cout << char(cur + 'A' - 1);
	if(rc[cur]) inOrder(rc[cur]);
}

void postOrder(int cur)
{
	if(lc[cur]) postOrder(lc[cur]);
	if(rc[cur]) postOrder(rc[cur]);
	cout << char(cur + 'A' - 1);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		char p, l, r;
		cin >> p >> l >> r;
		if(l!='.')
			lc[p-'A'+1] = l - 'A' + 1;
		if(r!='.')
			rc[p - 'A' + 1] = r - 'A' + 1;
	}

	preOrder(1);
	cout << "\n";
	inOrder(1);
	cout << "\n";
	postOrder(1);

	return 0;
}
