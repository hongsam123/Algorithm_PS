// p.178 ������ �Ʒ���
//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//bool comp(int a, int b)
//{
//	return a > b;
//}
//
//int main(void)
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	vector<int> v;
//	int n,x;
//	cin >> n;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> x;
//		v.push_back(x);
//	}
//	
//	// 1. reverse �Լ� ���
//	/*sort(v.begin(), v.end());
//	reverse(v.begin(), v.end());*/
//
//	//2. rbegin(), rend()
//	/*sort(v.rbegin(), v.rend());*/
//
//	//3. ���Լ� �μ��� �ѱ��
//	sort(v.begin(), v.end(), comp);
//
//	for (int i = 0; i < n; i++)
//		cout << v[i] << " ";
//	
//	return 0;
//}

// p.180 ������ ���� ������ �л� ����ϱ�
//#include<iostream>
//#include<vector>
//#include<utility>
//#include<algorithm>
//using namespace std;
//
//int main(void)
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	int n;
//	cin >> n;
//
//	vector<pair<int, string>> v;
//	string str;
//	int idx;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> str >> idx;
//		v.push_back({ idx,str });
//	}
//
//	sort(v.begin(), v.end());
//
//	for (int i = 0; i < n; i++)
//	{
//		cout << v[i].second << " ";
//	}
//
//	return 0;
//}

//p.182 �� �迭�� ���ұ�ü
//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//int main(void)
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	int n, k;
//	cin >> n >> k;
//	
//	int x;
//	vector<int> v1;
//	vector<int> v2;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> x;
//		v1.push_back(x);
//	}
//	for (int i = 0; i < n; i++)
//	{
//		cin >> x;
//		v2.push_back(x);
//	}
//
//	sort(v1.begin(), v1.end());
//	sort(v2.rbegin(), v2.rend());
//
//	int tmp;
//	for (int i = 0; i < k; i++)
//	{
//		if (v1[i] > v2[i]) break;
//		tmp = v1[i];
//		v1[i] = v2[i];
//		v2[i] = tmp;
//	}
//
//	int sum = 0;
//	for (int i = 0; i < n; i++)
//	{
//		sum += v1[i];
//	}
//
//	cout << sum;
//
//	return 0;
//}


//p.322 ���ڿ�������
//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//int main(void)
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	string str;
//	cin >> str;
//
//	vector<char> v;
//	int total = 0;
//
//	for (int i = 0; i < str.size(); i++)
//	{
//		if (str[i] - '0' >= 0 && str[i] - '0' <= 9)	//���ڶ��
//			total += str[i] - '0';
//		else
//		{
//			v.push_back(str[i]);
//		}
//	}
//	sort(v.begin(), v.end());
//
//	for (int i = 0; i < v.size(); i++)
//		cout << v[i];
//	cout << total;
//
//	return 0;
//}

//p.217 1�� �����
//#include<iostream>
//#include<algorithm>
//using namespace std;
//
//int dp[30002];
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
//	
//	for (int i = 2; i <= n; i++)
//	{
//		dp[i] = dp[i - 1] + 1;
//		if (i % 2 == 0)
//		{
//			dp[i] = min(dp[i / 2]+1, dp[i]);
//		}
//		else if (i % 3 == 0)
//		{
//			dp[i] = min(dp[i], dp[i / 3] + 1);
//		}
//		else if (i % 5 == 0)
//		{
//			dp[i] = min(dp[i], dp[i / 5]+1);
//		}
//	}
//
//	cout << dp[n];
//	return 0;
//}

//p.220 ��������
//1. ���̺� ����
//dp[i] = i��° �ķ�â�� ���� �� ���� �� �ִ� �ִ� �ķ��� ��
//2. ��ȭ�� ã��
//dp[i] = max(dp[i - 1], dp[i - 2]+arr[i])
//3.�ʱⰪ ����
//dp[1] = arr[1]
//dp[2] = arr[2]
//#include<iostream>
//#include<algorithm>
//using namespace std;
//
//int arr[102];
//int dp[102];
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
//		cin >> arr[i];
//
//	dp[1] = arr[1];
//	dp[2] = arr[2];
//
//	for (int i = 3; i <= n; i++)
//	{
//		dp[i] = max(dp[i - 2], dp[i - 3]) + arr[i];
//	}
//
//	cout << max(dp[n], dp[n - 1]);
//
//
//	return 0;
//}
//dp[i] = i��° �ķ� â�� �������� �� �ִ� �� �ķ��� ��
//#include<iostream>
//#include<algorithm>
//using namespace std;
//
//int arr[102];
//int dp[102];
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
//		cin >> arr[i];
//
//	dp[1] = arr[1];
//	dp[2] = max(arr[1],arr[2]);
//
//	for (int i = 3; i <= n; i++)
//	{
//		dp[i] = max(dp[i - 1], dp[i - 2] + arr[i]);
//	}
//
//	cout << dp[n];
//
//
//	return 0;
//}

//p.223 �ٴڰ���
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
//		dp[i] =( dp[i - 1] + 2 * (dp[i - 2]) )%796796;
//		/*���������� 10007�� ������ int overflow�߻�.
//		�߰��߰� ������ �����ؾ��Ѵ�*/
//	}
//
//	cout << dp[n];
//
//	return 0;
//}
//SDS �˰��� Ư��
//7/19
//boj 3425 ����
//boj 3055 Ż��
//boj 1062 ����ħ
//boj 1713 �ĺ� ��õ�ϱ�
//boj 1104 ����
//7/21
//boj 2042 ���� �� ���ϱ�
//7/22
//boj 2243 ��������
//boj 9202 Boggle
//boj 14476 �ִ����� �ϳ� ����