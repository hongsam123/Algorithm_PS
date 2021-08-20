#include<iostream>
#include<algorithm>
using namespace std;

const int MX = 5001;
int dat[MX], pre[MX], nxt[MX];
int unused = 1;

void insert(int addr, int num) {
	dat[unused] = num;
	pre[unused] = addr;
	nxt[unused] = nxt[addr];
	
	if (nxt[addr] != -1) pre[nxt[addr]] = unused;
	nxt[addr] = unused;
	unused++;
}

void erase(int addr) {
	nxt[pre[addr]] = nxt[addr];
	if(nxt[addr] != -1) pre[nxt[addr]] = pre[addr];
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	fill(pre, pre + MX, -1);
	fill(nxt, nxt + MX, -1);

	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; i++)
	{
		insert(i, i+1);
	}
	

	pre[1] = n;
	nxt[n] = 1;

	int cur = 0;
	int cnt = 0;
	cout << "<";
	while (cnt!=n)
	{
		for (int i = 0; i < k; i++)
			cur = nxt[cur];
		cout << dat[cur];
		cnt++;
		if (cnt == n)
			break;
		cout << ", ";
		erase(cur);
	}

	cout << ">";

	return 0;
}
