//DP�� Ǫ�� ����
//1. ���̺� �����ϱ�
//2. ��ȭ�� ã��
//3. �ʱⰪ ���ϱ�
//�ڵ��׽�Ʈ�� ���� ������ DP�� �ϴ� ��ȭ�ĸ� ã����
//�� �ڴ� �ʱⰪ�� ä������ �� �ݺ����� ���� �迭�� ä��� �ȴ�

// boj 1463 1�� �����
//1. ���̺� ����
//D[i] = i�� 1�� ����� ���� �ʿ��� ���� ��� Ƚ���� �ּڰ�
//2. ��ȭ�� ã��
//D[12] = min(D[4]+1, D[3]+1, D[11]+1)
//D[k] = min(D[k/3]+1, D[k/2]+1, D[k-1]+1
//3. �ʱⰪ ����
//D[i] = 0
//#include<iostream>
//#include<algorithm>
//using namespace std;
//
//int dp[1000002];
//
//int main(void)
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	int n;
//	cin >> n;
//
//	for (int i = 2; i <= n; i++)
//	{
//		dp[i] = dp[i - 1] + 1;
//		if (i % 3 == 0)
//			dp[i] = min(dp[i / 3] + 1, dp[i]);
//		if (i % 2 == 0)
//			dp[i] = min(dp[i / 2] + 1, dp[i]);
//	}
//
//	cout << dp[n];
//
//	return 0;
//}

//boj 9095 1,2,3 ���ϱ�
//1. ���̺� �����ϱ�
//D[i] = i�� 1,2,3�� ������ ��Ÿ���� ����� ��
//2. ��ȭ�� ã��
//D[4] = 
//1+1+1+1, 1+2+1, 2+1+1, 3+1 => 3�� 1,2,3�� ������ ��Ÿ���� ���+1 =>D[3]
//1+1+2, 2+2 => 2�� 1,2,3�� ������ ��Ÿ���� ���+2 => D[2]
//1+3 => 1�� 1,2,3�� ������ ��Ÿ���� ���+3 => D[1]
//D[i] = D[i-1]+D[i-2]+D[i-3]
//3. �ʱⰪ ����
//�ʱⰪ�� �ּ� 3���� �־�������(D[1],D[2],D[3])

//#include<iostream>
//using namespace std;
//
//int dp[13];
//
//int main(void)
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	dp[1] = 1;
//	dp[2] = 2;
//	dp[3] = 4;
//	for (int i = 4; i <= 10; i++)
//		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
//
//	int test;
//	cin >> test;
//
//	while (test--)
//	{
//		int n;
//		cin >> n;
//		
//		cout << dp[n] << "\n";
//	}
//
//	return 0;
//}

//boj 1,2,3 ���ϱ� 3

//boj 2579
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

//���� ���� Ǫ�� ���� �������� �ʴ�...^^
//�ֳĸ� �����ؼ� ������ ���� ���� ���� �ܼ��ϰԸ� �����
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
//#include<iostream>
//#include<algorithm>
//using namespace std;
//
//int score[302];
//int dp[302][3];
//
//int main(void)
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	int n;
//	cin >> n;
//
//	for (int i = 1; i <= n; i++)
//		cin >> score[i];
//
//	dp[1][1] = score[1];
//	dp[1][2] = 0;
//	dp[2][1] = score[2];
//	dp[2][2] = score[1] + score[2];
//
//	for (int i = 3; i <= n; i++)
//	{
//		dp[i][1] = max(dp[i - 2][1], dp[i - 2][2]) + score[i];
//		dp[i][2] = dp[i - 1][1] + score[i];
//	}
//
//	cout << max(dp[n][1], dp[n][2]);
//	return 0;
//}
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

//boj1149
//1. ���̺� �����ϱ�(���� ���� ������ �߰������� ���Բ� �����ؾ���)
//dp[i][0] = i��° ������ ĥ�� �� ����� �ּҰ�, ��, i��° ���� ����
//dp[i][1] = i��° ������ ĥ�� �� ����� �ּҰ�, ��, i��° ���� �ʷ�
//dp[i][2] = i��° ������ ĥ�� �� ����� �ּҰ�, ��, i��° ���� �Ķ�
//2. ��ȭ�� ã��
//dp[k][0] = min(dp[k - 1][1], dp[k - 1][2]) + cost[k][0]
//dp[k][1] = min(dp[k - 1][0], dp[k - 1][2]) + cost[k][1]
//dp[k][2] = min(dp[k - 1][0], dp[k - 1][1]) + cost[k][2]
//3. �ʱⰪ �����ϱ�
//dp[1][0] = cost[1][0]
//dp[1][1] = cost[1][1]
//dp[1][2] = cost[1][2]
//
//#include<iostream>
//#include<algorithm>
//using namespace std;
//
//int dp[1002][3];
//int cost[1002][3];
//
//int main(void)
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	int n;
//	cin >> n;
//
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 0; j < 3; j++)
//		{
//			cin >> cost[i][j];
//		}
//	}
//
//	dp[1][0] = cost[1][0];
//	dp[1][1] = cost[1][1];
//	dp[1][2] = cost[1][2];
//
//	for (int i = 2; i <= n; i++)
//	{
//		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + cost[i][0];
//		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + cost[i][1];
//		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + cost[i][2];
//	}
//
//	int min_cost = min(dp[n][0], dp[n][1]);
//	min_cost = min(min_cost, dp[n][2]);
//	//min_cost = min({ dp[n][0],dp[n][1],dp[n][2] });
//	//min_cost = *min_element(dp[n], dp[n] + 3);
//
//	cout << min_cost;
//
//	return 0;
//}

//boj11726 2*n Ÿ�ϸ�
//1. ���̺� �����ϱ�
//dp[i] = 2 * iũ���� ���簢���� ä��� ����� ��
//2. ��ȭ�� ã��
//�� ���� �� Ÿ���� 2 * 1�϶� ���� ĭ�� ä��� ����� �� = > dp[i - 1]
//�� ���� �� Ÿ���� 1 * 2�϶� ���� ĭ�� ä��� ����� �� = > dp[i - 2]
//dp[i] = dp[i - 1] + dp[i - 2]
//3. �ʱⰪ �����ϱ�
//dp[1] = 1
//dp[2] = 2


//boj11659
//#include<iostream>
//using namespace std;
//
//int arr[100002];
//int dp[100002];
//
//int main(void)
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	int n, m;
//	cin >> n >> m;
//	for (int i=1; i <= n; i++)
//	{
//		cin >> arr[i];
//	}
//
//	dp[1] = arr[1];
//	for (int i = 2; i <= n; i++)
//		dp[i] = dp[i - 1] + arr[i];
//
//	while (m--)
//	{
//		int a, b;
//		cin >> a >> b;
//		cout << dp[b] - dp[a - 1]<<"\n";
//	}
//
//	return 0;
//}

//boj12852
//�ܼ��� ���� ����ϴ� ���� �ƴ϶� ���Ŀ� ������ ����Ѵ�.
//�̷����� dp���̺��� ä��� �߰����� ������ ��򰡿� �����ؾ��Ѵ�
//�߰� ���� ������ �� ���̺�(��� ������ ���̺�)�� ���εд�.
//
//#include<iostream>
//#include<algorithm>
//using namespace std;
//
//int dp[1000002];
//int pre[1000002];
//
//int main(void)
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	
//	int n;
//	cin >> n;
//
//	dp[1] = 0;
//	pre[1] = 0;
//
//	for (int i = 2; i <= n; i++)
//	{
//		dp[i] = dp[i - 1] + 1;
//		pre[i] = i - 1;
//		if (i % 3 == 0 && dp[i] > dp[i / 3] + 1)
//		{
//			dp[i] = dp[i / 3] + 1;
//			pre[i] = i / 3;
//		}
//		if (i % 2 == 0 && dp[i] > dp[i / 2] + 1)
//		{
//			dp[i] = dp[i / 2] + 1;
//			pre[i] = i / 2;
//		}
//	}
//
//	cout << dp[n] << "\n";
//	int x = n;
//	cout << x << " ";
//	while (1)
//	{
//		if (x == 1) break;
//		cout<<pre[x]<<" ";
//		x = pre[x];
//	}
//
//	return 0;
//}

//boj 1932
//1. ���̺� �����ϱ�
//dp[i][j] = { i,j }��ο� �������� �ִ� ���� ����
//2. ��ȭ��
//dp[k][1] = dp[k - 1][1] + arr[k][1]
//dp[k][j] = max(dp[k-1][j - 1], dp[k-1][j]) + arr[k][j]
//dp[k][k] = dp[k - 1][k-1] + arr[k][k]
//3. �ʱⰪ �����ϱ�
//dp[1][1] = arr[1][1]

//#include<iostream>
//#include<algorithm>
//using namespace std;
//
//int arr[502][502];
//int dp[502][502];
//
//int main(void)
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	int n;
//	cin >> n;
//
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= i; j++)
//			cin >> arr[i][j];
//	}
//
//	dp[1][1] = arr[1][1];
//	if (n == 1)
//	{
//		cout << dp[1][1];
//		return 0;
//	}
//
//	dp[2][1] = dp[1][1] + arr[2][1];
//	dp[2][2] = dp[1][1] + arr[2][2];
//	if (n == 2)
//	{
//		cout << max(dp[2][1], dp[2][2]);
//		return 0;
//	}
//
//	for (int i = 3; i <= n; i++)
//	{
//		dp[i][1] = dp[i - 1][1] + arr[i][1];
//		for (int j = 2; j <= i - 1; j++)
//		{
//			dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + arr[i][j];
//		}
//		dp[i][i] = dp[i - 1][i - 1] + arr[i][i];
//	}
//
//	int max_cost = *max_element(dp[n], dp[n] + n+1);
//
//	cout << max_cost;
//
//	return 0;
//}

//boj 2193
//1. ���̺� �����ϱ�
//dp[i][0] = i��° �ڸ��� 0�� �ö� ��ģ���� ����
//dp[i][1] = i��° �ڸ��� 1�� �ö� ��ģ���� ����
//2. ��ȭ��
//dp[i][0] = dp[i - 1][0] + dp[i - 1][1]
//dp[i][1] = dp[i - 1][0]
//3. �ʱⰪ
//dp[1][0] = 0
//dp[1][1] = 1
//
//#include<iostream>
//using namespace std;
//
//int n;
//long long dp[92][2];
//
//int main(void)
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	cin >> n;
//
//	dp[1][0] = 0;
//	dp[1][1] = 1;
//
//	for (int i = 2; i <= n; i++)
//	{
//		dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
//		dp[i][1] = dp[i - 1][0];
//	}
//
//	cout << dp[n][0] + dp[n][1];
//
//	return 0;
//}

//boj11727
//1. ���̺� �����ϱ�
//dp[i] = 2 * iũ���� ���簢���� ä��� ����� ��
//2. ��ȭ�� ã��
//1) �� ���� �� Ÿ���� 1 * 2 Ÿ�� �� �� ���� ĭ�� ä��� ����� �� = > dp[i - 2]
//2) �� ���� �� Ÿ���� 2 * 1 Ÿ�� �� �� ���� ĭ�� ä��� ����� �� = > dp[i - 1]
//3) �� ���� �� Ÿ���� 2 * 2 Ÿ�� �� �� ���� ĭ�� ä��� ����� �� = > dp[i - 2]
//dp[i] = dp[i - 1] + 2 * (dp[i - 2])
//3. �ʱⰪ �����ϱ�
//dp[1] = 1
//dp[2] = 3
//
//#include<iostream>
//using namespace std;
//
//int dp[1002];
//
//int main(void)
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	int n;
//	cin >> n;
//	
//	dp[1] = 1;
//	dp[2] = 3;
//	for (int i = 3; i <= n; i++)
//	{
//		dp[i] =( dp[i - 1] + 2 * (dp[i - 2]) )%10007;
//		/*���������� 10007�� ������ int overflow�߻�.
//		�߰��߰� ������ �����ؾ��Ѵ�*/
//	}
//
//	cout << dp[n];
//
//	return 0;
//}


//boj14501 ���
//boj 18353 �����ġ�ϱ�
//1. ���̺� �����ϱ�
//dp[n] = ���� ���縦 ��ġ������ ������ �ִ� ���� ��
//2. ��ȭ�� ã��
//for (int j = 0; j <= i; j++)
//	if (arr[i] > arr[j]) dp[i] = max(dp[i], dp[j] + 1)
//
//LIS(Longest Increasing Subsequence)
//�ϳ��� ������ �־����� �� ������ �����ϴ� ������ ���� �� �κ� ������ ã�� ��ǥ���� dp
//#include<iostream>
//#include<algorithm>
//using namespace std;
//
//int n;
//long long dp[2002];
//long long arr[2002];
//
//int main(void)
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	long long max_num = 1;
//	cin >> n;
//	for (int i = 1; i <= n; i++)
//		cin >> arr[i];
//
//	fill(dp, dp + n + 1, 1);
//	
//	for (int i = n-1; i >= 1; i--)
//	{
//		for (int j = n; j > i; j--)
//		{
//			if (arr[i] > arr[j])
//				dp[i] = max(dp[i], dp[j] + 1);
//			max_num = max(max_num, dp[i]);
//		}
//	}
//
//	cout << n - max_num;
//
//	return 0;
//}

//boj 11053 ���� �� �����ϴ� �κ� ����(LCS)

//boj 2156 ������ �ý�(boj 2579�� ���)
//(�ϴٰ� �����߰����� ���� ū �����̾�����)
//
//#include<iostream>
//#include<algorithm>
//using namespace std;
//
//int n;
//int arr[10002];
//long long dp[10002];
//
//int main(void)
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	cin >> n;
//
//	for (int i = 1; i <= n; i++)
//	{
//		cin >> arr[i];
//	}
//
//	dp[0] = 0;
//	dp[1] = arr[1];
//	dp[2] = arr[1] + arr[2];
//	dp[3] = max(arr[1], arr[2]) + arr[3];
//
//	for (int i = 4; i <= n; i++)
//	{
//		dp[i] = max(dp[i-2] , arr[i - 1] + dp[i - 3])+arr[i];
//		dp[i] = max(dp[i],arr[i-1]+dp[i-4]+arr[i]);
//	}
//
//	if (n == 1)
//	{
//		cout << dp[n];
//		return 0;
//	}
//	cout << max(dp[n], dp[n - 1]);
//
//	return 0;
//}

//boj2294 ���� 2
//1.���̺�����
//dp[i] = i���� ������ �� ����ϴ� �ּ����� ȭ�󰳼�
//2.��ȭ�� ã��
//dp[i] = dp[arr[j]] + dp[i - arr[j]];
//3.�ʱⰪ ã��
//dp[arr[1]] = 1;
//...
//dp[arr[n]] = 1;
//
//#include<iostream>
//#include<algorithm>
//#include<vector>
//using namespace std;
//
//int n, k;
//vector<int> coin;
//int dp[100003];
//
//int main(void)
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	cin >> n >> k;
//
//	fill(dp, dp + 100002, 100001);
//
//	for (int i = 1; i <= n; i++)
//	{
//		int x;
//		cin >> x;
//		coin.push_back(x);
//		dp[x] = 1;
//	}
//
//	sort(coin.begin(), coin.end());
//
//	for (int i = 1; i <= k; i++)
//	{
//		if (dp[i]!=100001) continue;
//
//		for (int j = n-1; j >=0 ; j--)
//		{
//
//			if (coin[j] > i) continue;
//			if (dp[i - coin[j]] == 0) continue;
//			dp[i] = min(dp[i - coin[j]] + dp[coin[j]],dp[i]);
//			//ó�� �ڵ忡�� ���⼭ break�� �ɾ���.
//			//������ ������谡 �ƴϱ� ������ ū �׼��� ������ ����������� �ּҰ��̶�� ������ ����
//		}
//	}
//	
//	if (dp[k] == 100001)
//		cout << -1;
//	else
//		cout << dp[k];
//
//	return 0;
//}

//boj1912 ������
//boj9461 �ĵ��� ����
//boj10844 ���� ��� ��
//boj1699 �������� ��
//boj2133 Ÿ�� ä���