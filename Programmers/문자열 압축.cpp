#include <string>
#include <vector>
#include <iostream> 
using namespace std;

int solution(string s) {
    
    int answer = s.size();

    for (int size = 1; size <= s.size() / 2; size++) //1�� �������� �÷����� Ȯ��
    {
        string compressed = "";             //����� ���ڿ��� ������ ����
        string prev = "";                   //���� ���ڿ�
        int cnt = 1;
        bool impo = false;							//���̻� ������ �� ������ ǥ�� 
        for (int i = 0; i < size; i++)             //�տ������� size��ŭ s�� ���ڿ� ����(�ʱ� �� ���ڿ�)
            prev += s[i];

        for (int i = size; i < s.size(); i += size)  //����� ���ڿ� ���Ŀ� size��ŭ ���ذ��鼭 �� Ȯ��
        {
            string comp = "";
            for (int j = i; j < i + size; j++)
            {
                if (j >= s.size())				//������ ���ڿ� ó�� 
                {
                    if (cnt >= 2)                //�������� ������ ���ڿ��� �߰�
                    {
                        compressed += to_string(cnt);
                        compressed += prev;
                    }
                    else
                    {
                        compressed += prev;
                    }
                    compressed += comp;			//������ ���ڿ� 
                    impo = true;
                    break;
                }
                comp += s[j];
            }
            if (impo) break;				//���̻� ������ �� ������ break 

            if (prev == comp)               //���� size�� ���ڿ��� prev�� ���� ���
                cnt++;
            else        					//�ٸ� ���ڿ��� ���ͼ� �� �̻� �������� ���ϴ� ���
            {
                if (cnt >= 2)               //�������� ������ ���ڿ��� �߰�
                {
                    compressed += to_string(cnt);
                    compressed += prev;
                }
                else
                    compressed += prev;
                
                prev = "";                  //prev�� ���ο� ���ڿ��� �ʱ�ȭ
                for (int j = i; j < i + size; j++)
                {
                    prev += s[j];
                    cnt = 1;
                }
            }
        }
        if (!impo)							//�����ִ� ���ڿ� ó��
        {
            if (cnt >= 2)
            {
                compressed += to_string(cnt);
                compressed += prev;
            }
            else
                compressed += prev;
        }

        if (answer > compressed.size())
            answer = compressed.size();
    }
    return answer;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cout<<solution("aabbaccc")<<"\n";
	cout<<solution("abcabcabcabcdededededede")<<"\n";
	return 0;
 } 
