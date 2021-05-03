#include <string>
#include <vector>
#include <iostream> 
using namespace std;

int solution(string s) {
    
    int answer = s.size();

    for (int size = 1; size <= s.size() / 2; size++) //1개 단위부터 늘려가며 확인
    {
        string compressed = "";             //압축된 문자열을 저장할 변수
        string prev = "";                   //비교할 문자열
        int cnt = 1;
        bool impo = false;							//더이상 압축할 수 없음을 표시 
        for (int i = 0; i < size; i++)             //앞에서부터 size만큼 s의 문자열 추출(초기 비교 문자열)
            prev += s[i];

        for (int i = size; i < s.size(); i += size)  //추출된 문자열 이후에 size만큼 더해가면서 비교 확인
        {
            string comp = "";
            for (int j = i; j < i + size; j++)
            {
                if (j >= s.size())				//나머지 문자열 처리 
                {
                    if (cnt >= 2)                //이제까지 압축한 문자열을 추가
                    {
                        compressed += to_string(cnt);
                        compressed += prev;
                    }
                    else
                    {
                        compressed += prev;
                    }
                    compressed += comp;			//나머지 문자열 
                    impo = true;
                    break;
                }
                comp += s[j];
            }
            if (impo) break;				//더이상 압축할 수 없으면 break 

            if (prev == comp)               //같은 size의 문자열이 prev와 같은 경우
                cnt++;
            else        					//다른 문자열이 나와서 더 이상 압축하지 못하는 경우
            {
                if (cnt >= 2)               //이제까지 압축한 문자열을 추가
                {
                    compressed += to_string(cnt);
                    compressed += prev;
                }
                else
                    compressed += prev;
                
                prev = "";                  //prev를 새로운 문자열로 초기화
                for (int j = i; j < i + size; j++)
                {
                    prev += s[j];
                    cnt = 1;
                }
            }
        }
        if (!impo)							//남아있는 문자열 처리
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
