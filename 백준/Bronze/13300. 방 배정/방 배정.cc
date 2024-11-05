#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	// 입력
	int n, k; // 참가 학생 수, 한 방 최대 인원
	cin >> n >> k;
	int l[7][2] = {0}; // 학년 성별 별 학생 수 저장
	int t = 0; // 총 필요 방 수
	
	// 학생 정보 저장 & 분류
	for(int i = 0; i < n; i++){
		int gender, age;
		cin >> gender >> age;
		l[age][gender]++;
	}
	// 필요 방 수 계산
	for(int i = 1; i <= 6; i++){  // 1 ~ 6
		for(int j = 0; j < 2; j++){
			if(l[i][j] % k == 0){
				t += l[i][j]/k;
			} else
				t += l[i][j]/k + 1;
		}
	}
	
	// 출력
	cout << t;
	
	return 0;
}