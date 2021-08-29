#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

struct TrieNode
{
	TrieNode* children[26];
	bool isEnd;
	bool isHit;

	void clearHit() 
	{
		isHit = false;
		for (int i = 0; i < 26; i++)
		{
			if (children[i] != NULL)	//�ڽ��� ������ �ڽ��� clearHit()ȣ��
				children[i]->clearHit();
		}
	}
	TrieNode* getChild(char c)
	{
		return children[c - 'A'];
	}
	bool hasChild(char c)
	{
		return children[c - 'A'] != NULL;
	}
};

struct Trie
{
	TrieNode* root = new TrieNode();

	void insert(string word)
	{
		TrieNode* current = root;
		for (int i = 0; i < word.size(); i++)
		{
			char c = word[i];
			int index = c - 'A';
			if (current->hasChild(c) == false)
			{
				current->children[index] = new TrieNode();
			}
			current = current->getChild(c);
		}
		current->isEnd = true;
	}

	bool checkWord(string word)
	{
		TrieNode* current = root;
		for (int i = 0; i < word.size(); i++)
		{
			char c = word[i];
			if (current->hasChild(c))
				current = current->getChild(c);
			else
				return false;
		}
		return current->isEnd;
	}
};

int w, b;
char map[4][4];
bool visited[4][4];
vector<char> sol;
int dx[8] = { -1,0,1,-1,1,1,0,-1 };
int dy[8] = { -1,-1,-1,0,0,1,1,1 };
int score[] = { 0,0,0,1,1,2,3,5,11 };
int sum, cnt;
string answer;

bool cmp(string args0, string args1)
{
	if (args0.size() == args1.size())
	{
		int n = args0.compare(args1);
		if (n > 0)
			return true;
		else
			return false;
	}
	else
		return args0.size() < args1.size();
}

void dfs(int x, int y ,int length, TrieNode* node)
{
	//1. üũ��
	visited[x][y] = true;
	sol.push_back(map[x][y]);
	//2. �������� �����ߴ°�?
	if (node->isEnd==true && node->isHit==false)	//�ܾ� ���̰� hit�� �� ���� ������
	{
		node->isHit = true;
		sum += score[length];
		cnt++;
		string foundWord = "";
		for (int i = 0; i < sol.size(); i++)
			foundWord += sol[i];
		if (cmp(answer, foundWord))
			answer = foundWord;
	}
	//3. ����� ���� ��ȸ
	for (int dir = 0; dir < 8; dir++)
	{
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		//4. �����Ѱ�?
		if (nx < 0 || ny < 0 || nx >= 4 || ny >= 4) continue;
		if (visited[nx][ny]) continue;	//�湮���� �ʾҰ�
		if (!(node->hasChild(map[nx][ny]))) continue;	//node�� �ش� �ڽ��� ��������
		//5. ����
		dfs(nx, ny, length + 1, node->getChild(map[nx][ny]));
	}
	//6. üũ �ƿ�
	visited[x][y] = false;
	//sol.pop_back();
	sol.erase(sol.begin()+length-1);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	Trie trie;

	cin >> w;
	for (int i = 0; i < w; i++)
	{
		string str;
		cin >> str;
		trie.insert(str);
	}

	cin >> b;
	trie.root->clearHit();
	while (b--)
	{
		for (int i = 0; i < 4; i++)
			fill(map[i], map[i] + 4, 0);
		for (int i = 0; i < 4; i++)
			fill(visited[i], visited[i] + 4, 0);
		answer = "";
		sum = 0;
		cnt = 0;
		for (int i = 0; i < 4; i++)
		{
			string str;
			cin >> str;
			for (int j = 0; j < 4; j++)
			{
				map[i][j] = str[j];
			}
		}

		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				if (trie.root->hasChild(map[i][j]))
					dfs(i, j, 1, trie.root->getChild(map[i][j]));
			}
		}
		trie.root->clearHit();
		cout << sum << " " << answer << " " << cnt << "\n";
	}

	return 0;
}
