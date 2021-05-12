//p. 197 ��ǰ ã��
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
//	int n, m;
//	cin >> n;
//
//	vector<int> v1;
//	for (int i = 0; i < n; i++)
//	{
//		int x;
//		cin >> x;
//		v1.push_back(x);
//	}
//	sort(v1.begin(), v1.end());
//
//	cin >> m;
//
//	vector<int> v2;
//	for (int j = 0; j < m; j++)
//	{
//		int x;
//		cin >> x;
//		v2.push_back(x);
//	}
//
//	for (int i = 0; i < v2.size(); i++)
//	{
//		int target = v2[i];
//		int start = 0;
//		int end = v1.size();
//		int mid = (start + end) / 2;
//		bool posi = false;
//		while (1)
//		{
//			if (v1[mid] == target)
//			{
//				posi = true;
//				break;
//			}
//			if (start + 1 >= end) break;
//			if (target < v1[mid])
//			{
//				end = mid - 1;
//				mid = (start + end) / 2;
//			}
//			else
//			{
//				start = mid + 1;
//				mid = (start + end) / 2;
//			}
//		}
//		if (posi)
//			cout << "yes" << " ";
//		else
//			cout << "no" << " ";
//	}
//
//	return 0;
//}

//p. 201 ������ �� �����
//#include<iostream>
//#include<algorithm>
//#include<vector>
//using namespace std;
//
//int main(void)
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	int n, target;
//	cin >> n >> target;
//
//	vector<int> v;
//	for (int i = 0; i < n; i++)
//	{
//		int x;
//		cin >> x;
//		v.push_back(x);
//	}
//
//	sort(v.begin(), v.end());
//
//	int result =0;
//	int start = 0;			//ù��° �� ����
//	int end = v[v.size() - 1];	//������ �� ����
//	int mid = (start + end) / 2;//�� ����
//
//	while (1)
//	{
//		if (start > end) break;
//		int sum = 0;
//		int i = v.size() - 1;		//������ �� �ε���
//
//		while (1)
//		{
//			if (v[i] <= mid||i<=0) break;
//			sum += v[i] - mid;
//			i--;
//		}
//		if (sum < target)
//			end = mid - 1;
//		else
//		{
//			result = mid;
//			start = mid + 1;
//		}
//		mid = (start + end) / 2;
//	}
//
//	cout << result;
//
//	return 0;
//}


//boj 2110
//#include<iostream>
//#include<algorithm>
//#include<vector>
//using namespace std;
//
//int a[200002];
//
//int main(void)
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	int n, c;
//	cin >> n >> c;
//
//	vector<int> v;
//	for (int i = 0; i < n; i++)
//	{
//		int x;
//		cin >> x;
//		v.push_back(x);
//	}
//	sort(v.begin(), v.end());
//
//	for (int i = 0; i < c; i++)
//		a[i] = 0;
//	for (int j = c; j < n; j++)
//		a[j] = 1;
//
//	int answer = 0;
//
//	do{
//		vector<int> tmp;
//		for (int i = 0; i < n; i++)
//		{
//			if (a[i] == 0)
//			{
//				tmp.push_back(v[i]);
//			}
//		}
//
//		int pre = tmp[0];
//		int min_size = tmp[1] - tmp[0];
//		for (int i = 1; i < tmp.size(); i++)
//		{
//			min_size = min(min_size, tmp[i] - pre);
//			pre = tmp[i];
//		}
//
//		answer = max(answer, min_size);
//
//	} while (next_permutation(a, a + n));
//
//	cout << answer;
//
//
//	return 0;
//}
//
//==> �ð� �ʰ� (�̺� Ž������ Ǫ�� ����)
//������ ���� �ִ� �Ÿ��� ������ �ٿ������� ã�� �̺� Ž��
//mid���� ���� �ɼ� �ִ°�??�� Ȯ���ϸ� ���� ����������
//
//#include<iostream>
//#include<algorithm>
//#include<vector>
//using namespace std;
//
//int a[200002];
//
//int main(void)
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	int n, c;
//	cin >> n >> c;
//
//	vector<int> v;
//	for (int i = 0; i < n; i++)
//	{
//		int x;
//		cin >> x;
//		v.push_back(x);
//	}
//	sort(v.begin(), v.end());
//
//	int start = 1;	//������ ���� �Ÿ� �ּҰ�
//	int end = v[v.size() - 1] - v[0];	//������ ���� �Ÿ� �ִ밪
//	int mid = (end + start) / 2;	//������ ������ ���� �Ÿ��� ������ �߰���
//									//mid ���� ������Ѱ��� ã�´�
//	int answer = 0;
//	while (start <= end)
//	{
//		int house = v[0];	//�� ó�� ������ ������ ��
//		int cnt = 1;	//�����⸦ ����� �ִ� �� ����
//		for (int i = 1; i < n; i++)
//		{
//			if (house + mid <= v[i])	//���� ���� �� �ִٸ�
//			{
//				house = v[i];	//�����
//				cnt++;			//�����Ⱑ ������ �� ���� +1
//			}
//		}
//		if (cnt < c)	//�����⸦ c����ŭ ����� ���ٸ�
//						//(������ ���� �Ÿ����� mid�� �ʹ� ũ��)
//		{
//			end = mid - 1;	//������ ������ �� ���� �Ÿ��϶��� ����
//		}
//		else
//			//�����⸦ c�� �̻� ���� �� �ִٸ�
//		{
//			start = mid + 1;	//������ ������ �� ���� �Ÿ��϶��� �������� �˻�
//			answer = mid;	//���� ������ ���� ����
//		}
//
//		mid = (start + end) / 2;
//	}
//
//	cout << answer;
//
//	return 0;
//}

//boj1477�� �ްԼ� ����� (�ٽ� Ǯ��� ���� ����� ����)
//���� �� �Ÿ��� ��� �ްԼҸ� ����� �׸����� ����������
//���� Ž���� ����ȭ������ ���� ������ Ǯ �� �ִ� �Ķ��Ʈ�� Ž��
//(������ ũ�Ⱑ �۾Ƽ� �̺� Ž���� �� �ؾ��� �ʿ�� ����)
//�̹� �����ϴ� �ްԼ� ���� ������ �Ÿ��� �ΰ� ���ο� �ްԼҸ� ���� ��
//���� �ްԼ��� ������ m���� ���������� �Ѵ�
