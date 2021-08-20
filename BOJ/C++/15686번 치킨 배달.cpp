#include<iostream>
#include<algorithm>
#include<utility>
#include<vector>
#define X first
#define Y second
using namespace std;

int city[52][52];	//0은 빈 칸, 1은 집, 2는 치킨 집
int tmp[52][52];
vector<pair<int, int>> home;
vector<pair<int,int>> chicken;
bool visited[15];
int n, m;
int ans;

void getDist()
{
	int city_dist = 0;
	for(int i=0;i<home.size();i++)
	{
		int cur_dist = 987654321;
		for (int x = 0; x < n; x++)
		{
			for (int y = 0; y < n; y++)
			{
				if (tmp[x][y] == 1)	//치킨집
				{
					cur_dist = min(cur_dist, (abs(home[i].X - x) + abs(home[i].Y - y)));
				}
			}
		}
		city_dist += cur_dist;
	}
	if (ans == 0)
		ans = city_dist;
	else
		ans = min(ans, city_dist);

	return;
}

void func(int st,int cnt)	//현재 st번째까지 확인했고, 총 cnt개 확인했음
{
	//if (cnt >= m || st >= chicken.size())		
	//	return;
	//최대 m개라고 되어있지만, 상식적으로 치킨집 갯수가 최대일때 도시의 치킨거리가 가장 작다
	//즉 치킨집이 m개일때만 거리를 계산해야 시간을 줄일 수 있음
	if (cnt == m || st >= chicken.size())
	{
		getDist();
		return;
	}

	for (int i = st; i < chicken.size(); i++)
		//현재까지 확인한 치킨집 이후에만 확인해야 시간을 줄일 수 있음
	{
		auto cur = chicken[i];
		if (visited[i] == 0 && cnt < m)
		{
			visited[i] = 1;
			tmp[cur.X][cur.Y] = 1;
			//getDist();
			func(i + 1, cnt + 1);
			tmp[cur.X][cur.Y] = 0;
			visited[i] = 0;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> city[i][j];
			if (city[i][j] == 1)
				home.push_back({ i,j });
			if (city[i][j] == 2)
				chicken.push_back({ i,j });
		}
	}

	func(0,0);

	cout << ans;

	return 0;
}
