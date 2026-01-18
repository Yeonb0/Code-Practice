#include <iostream>
#include <algorithm>
using namespace std;

int P[10][10];
int S[6] = {0, 5, 5, 5, 5, 5};
int ans = 26;

bool check(int x, int y, int size) { // size 범위가 1인가?4
    if(x + size > 10 || y + size > 10) return false; // 종이 크기 넘어가면
	for(int i = x; i < x+size; i++) {
		for(int j = y; j < y+size; j++) {
			if(P[i][j] == 0) return false;
		}
	}
	return true;
}

void fill(int x, int y, int size, int num) { // size 만큼 num 으로 채우기
	for(int i = x; i < x+size; i++) {
		for(int j = y; j < y+size; j++) {
			P[i][j] = num;
		}
	}
}

void backtracking(int xy, int used) {
	if(xy == 100) { // break point 1 : 탐색 완료
		ans = min(used, ans);
		return;
	}
	if(ans <= used) return; // break point 2 : 최솟값 이상이면 종료
	int x = xy % 10;
	int y = xy / 10;
	
	// 현재 좌표 1이면
	if(P[x][y] == 1) {
		for(int i = 5; i >= 1; i--) {
			if(S[i] > 0 && check(x, y, i)) {
				S[i]--; // 종이 사용
				fill(x, y, i, 0); // 0으로 바꾸기
				backtracking(xy+1, used+1); // backtracking
				S[i]++; // 종이 채우기
				fill(x, y, i, 1); // 1로 바꾸기
			}
		}
	} else { // 현재 좌표 0이면
		backtracking(xy+1, used); // 다음 칸으로
	}
}	

	
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	for(int i = 0; i < 10; i++) {
		for(int j = 0; j < 10; j++) {
			cin >> P[i][j];
		}
	}
	backtracking(0, 0);
	if(ans == 26) cout << -1;
	else cout << ans;
	
	return 0;
}