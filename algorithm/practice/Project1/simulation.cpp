//다시 풀어보기

//boj16236번 아기상어
//boj19236번 청소년상어
//boj15683 감시
//boj18808 스티커 붙이기
//boj3190 뱀
//boj13335 트럭
//boj17144 미세먼지 안녕!
//카카오 기둥과 보 설치
//boj14499 주사위 굴리기
//boj11559 Puyo Puyo
//boj14891 톱니바퀴
//boj14503 로봇 청소기
//프로그래머스 2019카카오블라인드 후보키
//boj14500 테트로미노
//boj17070 파이프 옮기기 1(bfs)
//boj20056 마법사 상어와 파이어볼
//프로그래머스 2020 카카오 블라인드 외벽 점검
//boj17135 캐슬 디펜스
//boj17822 원판 돌리기
//boj21610 마법사 상어와 비바라기
//boj17140 이차원 배열과 연산
//boj16235 나무 재테크
//boj20057 마법사 상어와 토네이도

//구현
//boj3085 사탕게임
//boj10799 쇠막대기
//boj15686 치킨 배달
//프로그래머스 월간코드챌린지 시즌1 삼각 달팽이
//프로그래머스 월간코드챌린지 시즌1 3진법 뒤집기
//프로그래머스 2020 카카오 인턴십 수식 최대화
//boj21608 상어 초등학교
//1107 리모컨

#include<iostream>
using namespace std;

int n;
int ans;
int board[501][501];
int percentage[5][5] = {
	{0,0,0.02,0,0},
	{0,0.1,0.07,0.01,0},
	{0.05,0.45,0,0,0},
	{0,0.1,0.07,0.01,0},
	{0,0,0.02,0,0}
};
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };

void rotatePercentage() {

}

void moveSand() {

}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}

	int x = n / 2;
	int y = n / 2;
	int cnt = 1;
	int dir = 0;

	while (1) {
		for (int i = 0; i < 2; i++) {
			//두번씩 정해진 수만큼 직진
			for (int j = 0; j < cnt; j++) {
				moveSand();

				if (x == 0 && y == 0) {
					cout << ans;
					return 0;
				}
			}
			dir++;
			if (dir > 3) dir = 0;
			rotatePercentage();
		}
		cnt++;
	}
}