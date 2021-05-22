//1. ���̺� ����
//dp[i] = i��° ��ܿ� �ö����� ���� �� �ִ� �ִ� ����
//2. ��ȭ��
//dp[4] = min(dp[2] + score[4],dp[3] + score[4])
//dp[i] = min(dp[i-2]+score[i],dp[i-1]+score[i])
//3. �ʱⰪ
//dp[1] = score[1]
//dp[2] = score[1] + score[2]
//dp[3] = score[1] + score[3]
//#include<iostream>
//#include<algorithm>
//using namespace std;
//
//int dp[302];
//int score[302];
//
//int main(void)
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	int n;
//	cin >> n;
//	for (int i = 1; i <= n; i++)
//	{
//		cin >> score[i];
//	}
//
//	dp[1] = score[1];
//	dp[2] = score[1] + score[2];
//	dp[3] = score[1] + score[3];
//
//	for (int i = 4; i <= n; i++)
//		dp[i] = max(dp[i - 2] + score[i], dp[i - 1] + score[i]);
//
//	cout << dp[n];
//
//	return 0;
//}
//�� dp�� Ǭ�� �� ���� ���� ù��° Ǯ�� 
//���� ���� Ǫ�� ���� �������� �ʴ�...^^
//�����ؼ� ������ ���� ���� ���� �ܼ��ϰԸ� �����
//�ٽ�...!
//
//1. ���̺� �����ϱ�
//dp[i][j] = ������� j���� ����� �����ؼ� ��� i��° ��ܱ��� �ö� ���� ��
//���� ���� �ִ밪, �� i��° ����� �ݵ�� ��ƾ� ��
//2. ��ȭ�� ã��
//dp[k][1] = max(dp[k - 2][1] + score[k], dp[k - 2][2] + score[k])
//dp[k][2] = dp[k - 1][1] + score[k]
//3. �ʱⰪ ����
//dp[1][1] = score[1], dp[1][2] = 0
//dp[2][1] = score[2], dp[2][2] = score[1] + score[2];
#include<iostream>
#include<algorithm>
using namespace std;

int score[302];
int dp[302][3];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> score[i];

	dp[1][1] = score[1];
	dp[1][2] = 0;
	dp[2][1] = score[2];
	dp[2][2] = score[1] + score[2];

	for (int i = 3; i <= n; i++)
	{
		dp[i][1] = max(dp[i - 2][1], dp[i - 2][2]) + score[i];
		dp[i][2] = dp[i - 1][1] + score[i];
	}

	cout << max(dp[n][1], dp[n][2]);
	return 0;
}
//�׷��� �� ������ ������ �ٲ� 1���� �迭�� ������ �� ���� �ִ�
//1. ���̺� ����
//dp[i] = i��° ��ܱ��� �ö��� �� ���� ���� ����� ���� �ּҰ�,
//�� i��° ����� �ݵ�� ���� ���� ������� �����ؾ� ��
//2. ��ȭ�� ã��
//����) �����Ѱ��� �翬.�����ϴٸ� ���̺��� ������ ä������
//dp[i] = min(dp[i - 2], dp[i - 3]) + score[i]
//3. �ʱⰪ ����
//dp[1] = score[1], dp[2] = score[2], dp[3] = score[3]
//���� ����� ������ ����� �ݵ�� ��ƾ� �ϴ� 
//�� ����� �տ��� min(dp[n-1],dp[n-2])�� ����ȴ�

//#include<iostream>
//#include<algorithm>
//using namespace std;
//
//int dp[302];
//int score[302];
//
//int main(void)
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	int n;
//	cin >> n;
//
//	int total = 0;
//	for (int i = 1; i <= n; i++)
//	{
//		cin >> score[i];
//		total += score[i];
//	}
//
//	//����� 2�� �����϶� ����ó��
//	if (n <= 2)
//	{
//		cout << total;
//		return 0;
//	}
//
//	dp[1] = score[1];
//	dp[2] = score[2];
//	dp[3] = score[3];
//
//	for (int i = 4; i < n; i++)
//		dp[i] = min(dp[i - 2] + score[i], dp[i - 3] + score[i]);
//
//	cout << total - min(dp[n-2],dp[n-1]);
//	return 0;
//}
