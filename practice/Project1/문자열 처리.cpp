////문자열 알고리즘(KMP, 라빈카프)
//
//** 시간 복잡도를 크게 고려할 필요가 없는 상황에서 문자열을 빡세게 다루어야 할때는 파이썬을 사용하자..
//
//#include<iostream>
//using namespace std;
//int main()
//{
//	string a = "abcdef";
//	string b = "zxcvzxcv";
//	if (a < b) cout << "a는 b보다 사전순으로 앞\n";
//	else cout << "a는 보다 사전 순으로 뒤\n";
//	string c = a.substr(2, 3);	//c = "cde" : 2번째부터 3글자 추출
//	cout << c << "\n";
//	string d = "hello my name is eunsol";
//	int idx = d.find("my");	//idx = 6
//	cout << idx;
//	return 0;
//}

////KMP : 문자열 A안에 문자열 B가 들어있는지 판단

//단순 패턴 매칭
// - 한글자씩 비교해 연속으로 문자열 B와 글자가 매칭되는지 확인, 안되면 다시 돌아가기
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
//==> 단순하게 구현.위 방법은 최악의 경우 시간복잡도 O(|a||b|)
//
//KMP는 패턴매칭문제를 O(|a|+|b|)에 해결
//실패함수 개념을 사용
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
//boj 1786 찾기

////라빈카프 : 문자열에서 쓸 수 있는 해시함수



//카카오2019블라인드 오픈채팅방
//map, sstream 사용
//카카오 2020블라인드 1번 문자열압축
//프로그래머스 월간 챌린지 5월 2개 이하로 다른 비트
//bitset 사용
//boj5525 IOIOI
//프로그래머스 월간 챌린지 이진 변환 반복하기
//boj2941 크로아티아 알파벳
//프로그래머스 2018 카카오 블라인드 뉴스 클러스터링
//프로그래머스 2019 카카오 인턴십 불량 사용자