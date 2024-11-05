#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int h, m, s; // 현재 시각
	int d; // 소요 시간
		
	// 입력 
	cin >> h >> m >> s;
	cin >> d;
	
	// 시간 계산
	s += d % 60;
	m += (s / 60) + ((d % 3600)/ 60);
	h += (m / 60) + (d / 3600);
	
	// 넘으면 잘라내기
	s %= 60;
	m %= 60;
	h %= 24;
	
	// 출력
	cout << h << " " << m << " " << s;
	
	return 0;
}