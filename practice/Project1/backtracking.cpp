////next_permutation
//#include<iostream>
//#include<algorithm>
//using namespace std;
//
//int main(void)
//{
//	int a[3] = { 1,1,3 };
//	//next_permutation�� �̿��� ����
//	//
//	//nest_permutation�� ������ ������ ���������� �������� �� 
//	//���� ������ ����� true�� return�Ѵ�
//	//���� ������ ������ ���������� �������� �� ����
//	//������ �����̶�� false�� return
//	do {
//		for (int i = 0; i < 3; i++)
//		{
//			cout << a[i];
//		}
//		cout << "\n";
//	} while (next_permutation(a, a + 3));
//
//	cout << "\n";
//
//	//next_permutation�� �̿��� ����
//	int b[4] = { 0,0,1,1 };
//	do {
//		for (int i = 0; i < 4; i++)
//		{
//			if (b[i] == 0)
//				cout << i + 1;
//		}
//		cout << "\n";
//	} while (next_permutation(b, b + 4));
//	//���� 5���߿� 3���� ������ ���Ѵٸ�
//	//a[5] = {0,0,0,1,1}�� �迭�� ���� �� �ִ�
//
//	return 0;
//}

//boj15649 N�� M(1)
//boj15650 N�� M(2)
//boj15651 N�� M(3)
//boj15652 N�� M(4)
//boj15654 N�� M(5)
//boj15655 N�� M(6) (next_permutation)
//boj12101 1,2,3 ���ϱ� 2
//boj9663 N-Queen
//boj1182 �κм����� ��
// (�ٸ�Ǯ��)
// �� ���� ������ ������ ����ϸ� ��� �κм����� �� ���°��� Ʈ���� �׸��ٰ� ����
// �ð� ���⵵�� O(n^2) 
//boj18428 ���� ���ϱ�
//boj15656 N�� M(7)
//boj6603 �ζ�