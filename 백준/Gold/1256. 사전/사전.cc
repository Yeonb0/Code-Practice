#include <iostream>
#define MAX 1000000000
using namespace std;

long DP[201][201];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	long n, m, k;
	cin >> n >> m >> k;
	
	// DP 테이블 만들기
	for(int i = 0; i < 201; i++) {
		DP[i][0] = 1;
		DP[i][i] = 1;
		DP[i][1] = i;
	}
	for(int i = 2; i < 201; i++) {
		for(int j = 0; j <= i; j++) {
			DP[i][j] = DP[i - 1][j - 1] + DP[i - 1][j];
			if(DP[i][j] > MAX) {
				DP[i][j] = MAX + 1;
			}
		}
	}
	
	if(DP[n + m][m] < k) { // 주어진 자릿수로 만들 수 없음
		cout << "-1";
	} 
	
	else {
		while(!(n == 0 && m == 0)) {
			// a를 선택했을 때 남은 문자로 만들 수 있는 모든 경우의 수가 k보다 크면
			if(DP[n-1 + m][m] >= k) {
				cout << "a";
				n--;
			}
			 
			else { // 모든 경우의 수가 k 보다 작으면 
				cout << "z";
				k = k - DP[n-1 + m][m]; // k 값 업데이트
				m--;
			}
		}
	}
	return 0;
}