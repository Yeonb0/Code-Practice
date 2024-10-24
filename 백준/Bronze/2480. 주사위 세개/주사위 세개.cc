#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int a, b, c;
	cin >> a >> b >> c;
	
	if(a == b && b == c && c == a) // 모두 같을 때
		cout << 10000 + (1000 * a); // a, b, c 아무거나 넣어도 상관 없음
	else if(a == b || a == c) // a와 다른 눈이 같을 때
		cout << 1000 + (100 * a);
	else if(b == c) // b와 c가 같을 때
		cout << 1000 + (100 * b); // b, c 아무거나 넣어도 상관 없음
	else{ // a, b, c 모두 다를 때
		int max = (a > b) ? ((a > c) ? a : c) : ((b > c) ? b : c);
		cout << 100 * max;
	}	
	return 0;
}