//boj11047
//#include<iostream>
//using namespace std;
//
//int money[12];
//
//int main(void)
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	int n, k;
//	int cnt = 0;
//	cin >> n >> k;
//
//	for (int i = 0; i < n; i++)
//		cin >> money[i];
//
//	for (int i = n - 1; i >= 0; i--)
//	{
//		if (money[i] > k) continue;
//		int x = k / money[i];
//		k -= x * money[i];
//		cnt += x;
//		if (k == 0) break;
//	}
//	cout << cnt;
//
//	return 0;
//}

//boj1931
//증명 : 현재 최선의 선택을 하지 않았을 경우 
//		최선의 선택을 했을 때 보다 더 결과가 좋아질 수 없다는 것을 보인다
//그리디 - 현재 시간 t에서 시작할수 있는 모든 회의 중 가장
//			빨리 끝나는 회의를 선택
//그리디 증명 - 가장 빨리 끝나는 회의를 선택하지 않았을 경우
//				보장되는 가능한 회의의 수보다
//				가장 빨리 끝나는 회의를 선택했을 경우
//				보장되는 가능한 회의의 수가 크거나 같다 (위의 경우의 수만큼은 보장하기 때문에)
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
//	int n;
//	cin >> n;
//
//	vector<pair<int, int>> v;
//
//	for (int i = 0; i < n; i++)
//	{
//		int x, y;
//		cin >> x >> y;
//		v.push_back({ y,x });
//	}
//
//	sort(v.begin(), v.end());
//
//	int t = 0;
//	int cnt = 0;
//
//	for (int i = 0; i < v.size(); i++)
//	{
//		if (t > v[i].second) continue;
//		cnt++;
//		t = v[i].first;
//	}
//
//	cout << cnt;
//
//	return 0;
//}

//boj2217
//사용할 로프의 개수를 k개로 정해놨다고 생각.
//로프의 최대 중량을 정렬한 후 로프를 k개 고른다면
//w[n-k]*k
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
//	int n;
//	cin >> n;
//
//	vector<int> w;
//	for (int i = 0; i < n; i++)
//	{
//		int x;
//		cin >> x;
//		w.push_back(x);
//	}
//	sort(w.begin(), w.end());
//
//	int max_w = 0;
//	for (int k = 1; k <= n; k++)
//		max_w = max(max_w, w[n - k] * k);
//
//	cout << max_w;
//
//	return 0;
//}

//boj1026
//재배열 부등식
//하나의 배열을 오름차순, 다른 배열을 내림차순으로 재배열하고
//순서대로 각각 배열의 원소를 곱해서 더했을 때 합이 최소가 된다
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
//	int n;
//	cin >> n;
//	
//	vector<int> a;
//	vector<int> b;
//	for (int i = 0; i < n; i++)
//	{
//		int x;
//		cin >> x;
//		a.push_back(x);
//	}
//	for (int i = 0; i < n; i++)
//	{
//		int x;
//		cin >> x;
//		b.push_back(x);
//	}
//
//	sort(a.begin(), a.end());
//	sort(b.rbegin(), b.rend());
//
//	int sum = 0;
//	for (int i = 0; i < n; i++)
//	{
//		sum += a[i] * b[i];
//	}
//
//	cout << sum;
//
//	return 0;
//}

//boj11399
//#include<iostream>
//#include<algorithm>
//#include<vector>
//using namespace std;
//
//int n;
//int person[1002];
//vector<int> time;
//
//int main(void)
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	cin >> n;
//	for (int i = 0; i < n; i++)
//	{
//		int t;
//		cin >> t;
//		time.push_back(t);
//	}
//
//	sort(time.begin(), time.end());
//
//	for (int i = 0; i < n; i++)
//	{
//		int sum = 0;
//		for (int j = 0; j <= i; j++)
//		{
//			sum += time[j];
//		}
//		person[i] = sum;
//	}
//
//	int total = 0;
//	for (int i = 0; i < n; i++)
//		total += person[i];
//
//	cout << total;
//
//	return 0;
//}

//boj1541
//ㅋㅋ;근데 굳이 이렇게 안해도 마이너스가 나오기 전까지 더한 수에서 마이너스가 나오고 난 후 정수들 모두 더해서 빼면됨
//#include<iostream>
//#include<vector>
//using namespace std;
//
//vector<int> plus_v;
//vector<int> minus_v;
//
//int main(void)
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	string str;
//	cin >> str;
//
//	string pre_num = "";
//	int ans = 0;
//	int i = 0;
//	bool plus = true;
//
//	while(1)
//	{
//		if (i >= str.size()) 
//		{
//			int num = 0;
//			int x = 1;
//			for (int j = pre_num.size() - 1; j >= 0; j--)
//			{
//				num += (pre_num[j] - '0') * x;
//				x *= 10;
//			}
//			if (plus)
//				plus_v.push_back(num);
//			else
//				minus_v.push_back(num);
//			break;
//		}
//
//		if (str[i] - '0' >= 0 && str[i] - '0' <= 9)
//		{
//			pre_num += str[i];
//		}
//		else
//		{
//			int num = 0;
//			int x = 1;
//			for (int j = pre_num.size() - 1; j >= 0; j--)
//			{
//				num += (pre_num[j]-'0') * x;
//				x *= 10;
//			}
//
//			if (str[i] == '-')
//			{
//				if (plus)
//					plus_v.push_back(num);
//				else
//					minus_v.push_back(num);
//				plus = false;
//				pre_num = "";
//			}
//			else
//			{
//				if (plus)
//					plus_v.push_back(num);
//				else
//					minus_v.push_back(num);
//				pre_num = "";
//			}
//		}
//		
//		i++;
//	}
//
//
//	for (int i = 0; i < plus_v.size(); i++)
//	{
//		ans += plus_v[i];
//	}
//	for (int i = 0; i < minus_v.size(); i++)
//	{
//		ans -= minus_v[i];
//	}
//
//	cout << ans;
//
//
//	return 0;
//}

//boj2847 게임을 만든 동준이
//boj1439 뒤집기
//boj5014 스타트링크 -> bfs로 다시 풀어보기