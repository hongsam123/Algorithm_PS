
//#include<iostream>
//#include<queue>
//#include<utility>
//#define X first
//#define Y second
//using namespace std;
//
//char board[1002][22];
//int leftright[1002][22];
//bool changeLeftright [1002][22] ;
////int dist[1002][22];
//int visit[1002][22];
//
//int dx[3] = { 1, 0, 0 };
//int dy[3] = { 0, -1, 1 };
//queue<pair<int, int>> q;
//
//int main(void)
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	int n, m;
//	cin >> m >> n;
//	vector<int> v;
//
//	string x;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> x;
//		for (int j = 0; j < m; j++)
//		{
//			board[i][j] = x[j];
//		}
//	}
//	
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < m; j++)
//		{
//			if (board[i][j] == 'c')
//			{
//				q.push({ i,j });
//				//cout << i << " " << j << "\n";
//				for (int h = 0; h < n; h++)
//				{
//					fill(visit[h], visit[h] + m, 0);
//					fill(leftright[h], leftright[h] + m, -1);
//				}
//
//				while (!q.empty())
//				{
//					pair<int, int> cur = q.front(); q.pop();
//					for (int dir = 0; dir < 3; dir++)
//					{
//						int nx = cur.X + dx[dir];
//						int ny = cur.Y + dy[dir];
//						if (nx < 0 || nx >= n || ny >= m) continue;
//						if (board[nx][ny] != '.' || visit[nx][ny] != 0) continue;
//						visit[nx][ny] = 1;
//						if (ny != cur.Y)	//좌우로 이동
//						{
//							if (changeLeftright[nx][ny])	//이전에 바뀐적 있고 갱신하면 최소값이 갱신되는 경우
//							{
//								leftright[nx][ny] = leftright[cur.X][cur.Y] + 1;
//							}
//							if (!changeLeftright[nx][ny])
//							{
//								changeLeftright[nx][ny] = true;
//								leftright[nx][ny] = 1;
//							}
//						}
//						else
//						{
//							if (!changeLeftright[nx][ny])
//							{
//								changeLeftright[nx][ny] = true;
//								leftright[nx][ny] = 0;
//							}
//							else
//							{
//								leftright[nx][ny] = leftright[cur.X][cur.Y];
//							}
//						}
//						q.push({ nx,ny });
//					}
//
//				}
//				cout << "\n";
//				for (int i = 0; i < n; i++)
//				{
//					for (int j = 0; j < m; j++)
//					{
//						cout << leftright[i][j] << " ";
//					}
//					cout << "\n";
//				}
//
//				for (int s = 0; s < m; s++)
//				{
//					if (visit[n - 1][s])
//					{
//						v.push_back(leftright[n - 1][s]);
//						cout << leftright[n - 1][s] << " ";
//					}
//				}
//			}
//		}
//	}
//	
//	int min;
//	if (v.empty()) cout << -1 << "\n";
//	else
//	{
//		min = v[0];
//		for (int i = 0; i < v.size(); i++)
//		{
//			if (v[i] < min) min = v[i];
//		}
//		cout << min << "\n";
//	}
//
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < m; j++)
//		{
//			cout << leftright[i][j] << " ";
//		}
//		cout << "\n";
//	}
//
//
//	return 0;
//}

//#include<iostream>
//#include<queue>
//#include<stack>
//#include<algorithm>
//using namespace std;
//
//int n, m, v;
//vector<int> board[1002];
//queue<int> dfs_q;
//queue<int> q;
//int bfs_visited[1002];
//int dfs_visited[1002];
//
//void dfs()
//{
//	while (!dfs_q.empty())
//	{
//		int cur = dfs_q.front(); dfs_q.pop();
//		cout << cur << " ";
//		if (!board[cur].empty())
//		{
//			for (int i = 0; i < board[cur].size(); i++)
//			{
//				int nx = board[cur][i];
//				if (dfs_visited[nx] == 1) continue;
//				dfs_visited[nx] = 1;
//				dfs_q.push(nx);
//				dfs();
//			}
//		}
//	}
//	return;
//}
//
//void bfs()
//{
//	while (!q.empty())
//	{
//		int cur = q.front(); q.pop();
//		cout << cur <<" ";
//		if (!board[cur].empty())
//		{
//			for (int i = 0; i < board[cur].size(); i++)
//			{
//				int nx = board[cur][i];
//				if (bfs_visited[nx] == 1) continue;
//				bfs_visited[nx] = 1;
//				q.push(nx);
//			}
//		}
//	}
//}
//
//int main(void)
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	cin >> n >> m >> v;
//
//	for (int i = 0; i < m; i++)
//	{
//		int a, b;
//		cin >> a >> b;
//		board[a].push_back(b);
//		board[b].push_back(a);
//	}
//
//	for (int i = 1; i <= n; i++)
//	{
//		sort(board[i].begin(), board[i].end());
//	}
//
//	dfs_q.push(v);
//	q.push(v);
//	dfs_visited[v] = 1;
//	bfs_visited[v] = 1;
//
//	dfs();
//	cout << "\n";
//	bfs();
//
//	return 0;
//}

//boj4673번
//#include<iostream>
//using namespace std;
//
//bool arr[10001];
//
//int main(void)
//{
//
//	for(int num = 1 ; num <= 10000 ; num++)
//	{
//		int sum = 0;
//		int tmp = num;
//		int a;
//		while (1)
//		{
//			a = tmp % 10;
//			tmp = tmp / 10;
//			sum += a;
//			if (tmp == 0) break;
//			//cout << tmp;
//		}
//		sum += num;
//
//		if (arr[sum] == 0 && sum <= 10000)
//			arr[sum] = 1;
//	}
//	//처음에 sum이 10000 이상이 되기 전까지 무한루프 돌렸다가 틀림
//	//num이 10000이하일때까지 돌려야댐 sum이 무조건 점점 커진다는 보장이 없음
//
//	for (int i = 1; i <= 10000; i++)
//	{
//		if (!arr[i])
//			cout << i << "\n";
//	}
//
//	return 0;
//}

//// boj 1620
//#include<iostream>
//#include<vector>
//#include<utility>
//#include<algorithm>
//using namespace std;
//
//int n, m;
//string ball[100002];
//vector<pair<string,int>> tmp;
//
//int main(void)
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	cin >> n >> m;
//	tmp.push_back({ "0",0 });
//
//	for (int i = 1; i <= n; i++)
//	{
//		string monster;
//		cin >> monster;
//		ball[i] = monster;
//		tmp.push_back( { monster,i } );
//	}
//	sort(tmp.begin() + 1, tmp.end());
//	//pair를 원소로 가지는 vector를 정렬하면 pair의 first를 기준으로 정렬된다
//	//first 값이 같을 경우 second를 기준으로 정렬
//
//	while (m--)
//	{
//		string test;
//		cin >> test;
//		if (test[0] - '0' <= 9)	//입력이 숫자라면
//		{
//			int n = 1;
//			int idx = 0;
//			for (int i = test.size() - 1; i >= 0; i--)
//			{
//				idx += n * (test[i]-'0');
//				n *= 10;
//			}
//			cout << ball[idx] << "\n";
//		}
//		else//문자라면
//			//시간복잡도를 줄이려면 이분탐색
//		{
//			int start = 1;
//			int end = n;
//			int mid = (start + end) / 2;
//			while (1)
//			{
//				if (tmp[mid].first == test)
//				{
//					cout << tmp[mid].second << "\n";
//					break;
//				}
//				else if (test < tmp[mid].first)
//				{
//					end = mid-1;
//					mid = (start + end) / 2;
//				}
//				else
//				{
//					start = mid+1;
//					mid = (start + end) / 2;
//				}
//			}
//		}
//	}
//
//	return 0;
//}


//#include <string>
//#include <vector>
//#include<utility>
//#include<algorithm>
//
//using namespace std;
//bool visited[300002];
//
//long long solution(vector<int> a, vector<vector<int>> edges) {
//	long long answer = 0;
//
//	long long sum = 0;
//	for (long long i = 0; i < a.size(); i++)
//	{
//		sum += a[i];
//	}
//	if (sum != 0)
//		return -1;
//
//	long long n = a.size();
//
//	vector<vector<long long>> v;
//	v.resize(n);
//
//	for (long long i = 0; i < edges.size(); i++)
//	{
//			long long a = edges[i][0];
//			long long b = edges[i][1];
//			v[a].push_back(b);
//			v[b].push_back(a);
//	}
//
//	vector<pair<long long, long long>> pairv;
//	for (long long i = 0; i < n; i++)
//	{
//		pairv.push_back({ v[i].size(),i });
//	}
//	
//	sort(pairv.begin(), pairv.end());
//
//	for (long long i = 0; i < n; i++)
//	{
//		long long x = pairv[i].second;
//		long long num = a[x];
//		a[x] -= num;
//		visited[x] = true;
//		bool posi = false;
//		long long b = 0;
//		if (v[x].empty()) return -1;
//		for (long long j = 0; j < v[x].size(); j++)
//		{
//			if (visited[v[x][j]]) continue;
//			posi = true;
//			b = v[x][j];
//		}
//		if (!posi) return -1;
//		a[b] += num;
//
//		if (num < 0)
//			answer += (-1) * num;
//		else
//			answer += num;
//	}
//	for (long long i = 0; i < a.size(); i++)
//	{
//		if (a[i] != 0)
//			return -1;
//	}
//
//	return answer;
//}

//#include<iostream>
//#include<sstream>
//#include<vector>
//#include<map>
//#include<set>
//using namespace std;
//
//map<string, int> ans;	//<id_list, 받을 메일 수>
//map<string, set<string>> report_list;	
//
//vector<int> solution(vector<string> id_list, vector<string> report, int k) {
//    vector<int> answer;
//
//	//stringstream ss;
//	cout << report.size();
//
//	for (int i = 0; i < report.size(); i++) {
//		stringstream ss;
//		ss.str(report[i]);
//		string a, b;	//신고한 사람, 당한 사람
//		ss >> a >> b;
//		report_list[b].insert(a);
//	}
//
//	for (auto e : report_list) {
//		if (e.second.size() >= k) {
//			for (auto x : e.second) {
//				ans[x]++;
//			}
//		}
//	}
//
//	for (int i = 0; i < id_list.size(); i++) {
//		answer.push_back(ans[id_list[i]]);
//	}
//
//    return answer;
//}
//
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	vector<int> v = solution({ "muzi", "frodo", "apeach", "neo" }, { "muzi frodo","apeach frodo","frodo neo","muzi neo","apeach muzi" }, 2);
//	for (int e : v) {
//		cout << e << " ";
//	}
//	
//
//	return 0;
//}
//
//#include <string>
//#include<vector>
//#include<algorithm>
//#include<iostream>
//using namespace std;
//
//int N;
//int max_diff;	//최대 점수 차
//vector<int> apeach;
//int arr[11];
//vector<int> ans;
//
//void getScore() {
//	int apeach_score = 0;
//	int ryan_score = 0;
//	for (int i = 0; i <= 10; i++) {
//		if (arr[i] == 0 && apeach[i] == 0) continue;
//		if (arr[i] > apeach[i]) ryan_score += 10 - i;
//		else apeach_score += 10 - i;
//	}
//	if (apeach_score >= ryan_score) return;
//	cout << apeach_score << " " << ryan_score << "\n";
//	int diff = abs(apeach_score - ryan_score);
//
//	if (max_diff < diff) {
//		max_diff = diff;
//		ans.clear();
//		for (int i = 0; i <= 10; i++) ans.push_back(arr[i]);
//		return;
//	}
//	if (max_diff == diff) {
//		//낮은 점수를 더 많이 맞힌 경우
//		for (int i = 10; i >= 0; i--) {
//			if (ans[i] == arr[i]) continue;
//			if (ans[i] > arr[i]) return;
//			else break;
//		}
//		ans.clear();
//		for (int i = 0; i <= 10; i++) ans.push_back(arr[i]);
//		return;
//	}
//}
//
//void func(int x, int k) {
//	if (k == N) {
//		for (int i = 0; i < 11; i++) {
//			cout << arr[i] << " ";
//		}
//		cout << "\n";
//		getScore();
//		return;
//	}
//
//	for (int i = x; i <= 10; i++) {
//		if (arr[i] > apeach[i]) continue;
//		arr[i]++;
//		func(i, k + 1);
//		arr[i]--;
//	}
//}
//
//vector<int> solution(int n, vector<int> info) {
//	vector<int> answer;
//
//	N = n;
//	apeach = info;
//	func(0, 0);
//
//	if (ans.empty()) answer.push_back(-1);
//	else answer = ans;
//
//	return answer;
//}
//
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	vector<int> v = solution(5, { 2,1,1,1,0,0,0,0,0,0,0 });
//	for (int e : v) {
//		cout << e << " ";
//	}
//
//
//	return 0;
//}

#include <string>
#include <vector>
#include <iostream>
#define ll long long
using namespace std;

struct COMMAND
{
	int x;
	int y;
	int xx;
	int yy;
	int Value;
};

int n;
vector<vector<int>> map;
ll fenwickTree[1002][1002];
vector<COMMAND> cmd;

void update(int x, int y, ll val) {
	while()
}

void make_fenwickTree() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < n; j++) {
			update(i, j, map[i][j]);
		}
	}
}

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;

	map = board;
	n = board.size();
	make_fenwickTree();

	for (int i = 0; i < skill.size(); i++) {
		int type = skill[i][0];
		int r1 = skill[i][1];
		int c1 = skill[i][2];
		int r2 = skill[i][3];
		int c2 = skill[i][4];
		int diff = skill[i][5];



		
	}

    return answer;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int x = solution({ {5, 5, 5, 5, 5},{5, 5, 5, 5, 5},{5, 5, 5, 5, 5},{5, 5, 5, 5, 5} });
	cout << x;


	return 0;
}