#include <iostream>
#include <cmath> // 절댓값 계산
using namespace std;

int Q[15]; // 퀸 위치
int n; // 체스판 크기
int ans = 0; // 정답 수

bool check(int row) {
	for(int i = 0; i < row; ++i) {
		if(Q[i] == Q[row]) return false; // 직선
		if(abs(row - i) == abs(Q[i] - Q[row])) return false; // 대각선
	}
	return true;
}

void backtracking(int row) {
	if(row == n) { // break point
		ans++;
		return;
	}
	for(int i = 0; i < n; ++i) { // 0은 이미 포함
		Q[row] = i; // i번째에 퀸 배치;
		if(check(row)) { // 배치 가능 하면
			backtracking(row + 1); // 다음 재귀
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	
	backtracking(0);
	cout << ans;
	
	return 0;
}