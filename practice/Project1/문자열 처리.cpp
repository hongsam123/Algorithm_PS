////���ڿ� �˰���(KMP, ���ī��)
//
//** �ð� ���⵵�� ũ�� ����� �ʿ䰡 ���� ��Ȳ���� ���ڿ��� ������ �ٷ��� �Ҷ��� ���̽��� �������..
//
//#include<iostream>
//using namespace std;
//int main()
//{
//	string a = "abcdef";
//	string b = "zxcvzxcv";
//	if (a < b) cout << "a�� b���� ���������� ��\n";
//	else cout << "a�� ���� ���� ������ ��\n";
//	string c = a.substr(2, 3);	//c = "cde" : 2��°���� 3���� ����
//	cout << c << "\n";
//	string d = "hello my name is eunsol";
//	int idx = d.find("my");	//idx = 6
//	cout << idx;
//	return 0;
//}

////KMP : ���ڿ� A�ȿ� ���ڿ� B�� ����ִ��� �Ǵ�

//�ܼ� ���� ��Ī
// - �ѱ��ھ� ���� �������� ���ڿ� B�� ���ڰ� ��Ī�Ǵ��� Ȯ��, �ȵǸ� �ٽ� ���ư���
//bool find(string& a, stirng& b)
//{
//	if (a.size() < b.size()) return false;
//	for (int st = 0; st <= a.size() - b.size(); st++)
//	{
//		bool isMatch = true;
//		for (int i = st; i <= st + b.size(); i++)
//		{
//			if (a[i] != b[i - st])
//			{
//				isMatch = false;
//				break;
//			}
//		}
//		if (isMatch) return true;
//	}
//	return false;
//}
//==> �ܼ��ϰ� ����.�� ����� �־��� ��� �ð����⵵ O(|a||b|)
//
//KMP�� ���ϸ�Ī������ O(|a|+|b|)�� �ذ�
//�����Լ� ������ ���
//vector<int> failure(string& s)
//{
//	vector<int> f(s.size());
//	int j = 0;
//	for (int i = 1; i < s.zie(); i++)
//	{
//		while (j > 0 && s[i] != s[j]) j = f[j - 1];
//		if (s[i] == s[j]) f[i] = ++j;
//	}
//	return f;
//}
//boj 1786 ã��

////���ī�� : ���ڿ����� �� �� �ִ� �ؽ��Լ�



//īī��2019����ε� ����ä�ù�
//map, sstream ���
//īī�� 2020����ε� 1�� ���ڿ�����
//���α׷��ӽ� ���� ç���� 5�� 2�� ���Ϸ� �ٸ� ��Ʈ
//bitset ���
//boj5525 IOIOI
//���α׷��ӽ� ���� ç���� ���� ��ȯ �ݺ��ϱ�
//boj2941 ũ�ξ�Ƽ�� ���ĺ�
//���α׷��ӽ� 2018 īī�� ����ε� ���� Ŭ�����͸�
//���α׷��ӽ� 2019 īī�� ���Ͻ� �ҷ� �����