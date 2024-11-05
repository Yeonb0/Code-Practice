#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int a, b;
	int c;
	int h, m; // 완료 시간
	
	// 입력
	cin >> a >> b; // 현재 시각
	cin >> c; // 소요 시간
	
	// 시간 계산 
	h = a;
	if(b+c >= 60){
		m = (b+c) % 60;
		h += (b+c) / 60;
	} else 
		m = b+c;
	if(h >= 24)
		h -= 24;
	
	// 출력
	cout << h << " " << m;
	
	return 0;
}