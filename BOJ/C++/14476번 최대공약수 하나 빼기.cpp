#include<iostream>
using namespace std;

int n;
int nums[1000003];
int gcdLtoR[1000003];
int gcdRtoL[1000003];

//gcd(a,b) == gcd(a, a%b), stop when a%b==0
int gcd(int a, int b)
{
	while (b != 0)
	{
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> nums[i];

	//LtoR
	gcdLtoR[0] = nums[0];
	for (int i = 1; i <= n; i++)
		gcdLtoR[i] = gcd(gcdLtoR[i - 1], nums[i]);
	
	//RtoL
	gcdRtoL[n - 1] = nums[n - 1];
	for (int i = n - 2; i >= 0; i--)
		gcdRtoL[i] = gcd(gcdRtoL[i + 1], nums[i]);

	int max = -1;
	int maxIndex = 0;
	for (int i = 0; i < n; i++)
	{
		int result = 0;
		if (i == 0)
			result = gcdRtoL[1];
		else if (i == n - 1)
			result = gcdLtoR[n - 2];
		else
			result = gcd(gcdLtoR[i - 1], gcdRtoL[i + 1]);

		if (nums[i] % result != 0 && result > max)
		{
			max = result;
			maxIndex = nums[i];
		}
	}

	cout << max << " ";
	if (max != -1) cout << maxIndex;

	return 0;
}
