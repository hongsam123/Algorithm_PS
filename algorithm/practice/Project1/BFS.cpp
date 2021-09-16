//pair example

//#include<iostream>
//#include<utility>
//using namespace std;
//
//int main(void)
//{
//	pair<int, int> t1 = make_pair(10, 13);
//	pair<int, int> t2 = { 4,6 };	//C++11 �̻�
//
//	cout << t2.first << ' ' << t2.second << '\n';
//	if (t2 < t1) cout << "t2 < t1";
//}

//#include<iostream>
//#include<queue>
//#include<utility>
//#define X first
//#define Y second
//using namespace std;
//
//int board[502][502] ={ 
//	{1,1,1,0,1,0,0,0,0,0},
//	{1,0,0,0,1,0,0,0,0,0},
//	{1,1,1,0,1,0,0,0,0,0},
//	{1,1,0,0,1,0,0,0,0,0},
//	{0,1,0,0,0,0,0,0,0,0},
//	{0,0,0,0,0,0,0,0,0,0},
//	{0,0,0,0,0,0,0,0,0,0} }; // 1�� �Ķ� ĭ, 0�� ���� ĭ�� ����
//
//bool visit[502][502];	// �ش� ĭ�� �湮�ߴ��� ���θ� ����
//int n = 7, m = 10;		// ��� ���� ��
//int dx[4] = { 1,0,-1,0 };
//int dy[4] = { 0,1,0,-1 };	// �����¿� �� ����
//int main(void)
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	queue<pair<int, int>> q;
//	visit[0][0] = 1;	// (0,0)�� �湮�ߴٰ� ����
//	q.push({ 0,0 });	// ť�� �������� (0,0)�� ����.
//
//	while (!q.empty())
//	{
//		pair<int, int> cur = q.front(); q.pop();
//		cout << '(' << cur.X << ', ' << cur.Y << ')->';
//		for (int dir = 0; dir < 4; dir++)	// �����¿� �� ���Ǳ�
//		{
//			int nx = cur.X + dx[dir];
//			int ny = cur.Y + dy[dir];	// nx, ny�� dir���� ���� ������ ĭ�� ��ǥ�� ��
//			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;	// ���� ���� ��� �Ѿ
//			if (visit[nx][ny] || board[nx][ny] != 1) continue;		// �̹� �湮�� ĭ�̰ų� �Ķ� ĭ�� �ƴ� ���
//			visit[nx][ny] = 1;	// (nx,ny)�� �湮�ߴٰ� ����
//			q.push({ nx, ny });
//		}
//	}
//}

//stl tuple����

//boj1926 �׸�
//boj2178 �̷� Ž��
//boj7576 �丶��
//boj4179 ��!
//------------------------------------------------------
//�߰��� �����ڸ��� ������ ��쿡��(������ ����ٴ� ����)
//Ż�⿡ �����ߴٴ� �ǹ��̹Ƿ� ť�� �Ÿ� ������ ���� ������ ���ʿ� Ż���� �ð��� ����� �� �ִ�.
//ť�� �� �ݺ����� Ż���ϸ� �̷� Ż�⿡ �����ߴٴ� �ǹ�. �ٷ� impossible�� ����� �� �ִ�.

//but�̰� �ϳ��� bfs�� ���� ���� �ٸ� bfs�� �� ����. 
//���� �� bfs�� �ٸ� bfs�� ������ ��ģ�ٸ� �̷�������� �Ҽ� ����.
//�ð������� bfs�� ���ÿ� ��������.

//==> �ٽ� Ǯ� ����
//-------------------------------------------------------
//boj5427 �� (�� ������ ���� ����)
//boj1697 ���ٲ���
//boj1325 ȿ������ ��ŷ
//(���α� �Խ� �� bfs(�ð��ʰ�) -> dfs(���))
//boj1012 ����� ����
//boj7569 �丶��
//boj2583 ���� ���ϱ�
//boj9466 �� ������Ʈ
//==> ���α� �Խ��ϸ鼭 �ٽ� �����غ���
//boj2667 ������ȣ���̱�
//boj7562 ����Ʈ�� �̵�
//boj10026 ���ϻ���
//boj11724 ���� ����� ����
//boj4963 ���� ����
//boj2468 ��������
//boj2573 ����
//==> ���4 �ٽ� �����غ���
//boj18405 ������ ����
//boj2146 �ٸ� �����
//boj18352 Ư�� �Ÿ��� ���� ã��
//boj16956 ����� ��
//boj14502 ������
//boj2606 ���̷���
//boj3184 ��
//boj6593 ��� ����
//boj16234 �α��̵�
//boj5014 ��ŸƮ��ũ
//boj3187 ��ġ�� ��
//boj13549 ���ٲ��� 3
//boj13565 ħ��
//boj13913 ���ٲ��� 4
//boj12851 ���ٲ��� 2
//boj1600 ���� �ǰ��� ������
//boj11967 ���ѱ�
//boj16928 ��� ��ٸ� ����
//���α׷��ӽ� 2021 īī�� ä�뿬���� ���Ͻ� �Ÿ��α�
//���α׷��ӽ� 2020 īī�� ���Ͻ� ���ַ� �Ǽ�
//boj1039�� ��ȯ