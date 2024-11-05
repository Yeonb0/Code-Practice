#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	// 입력
	int a, b;
	cin >> a >> b;
	
	// 출력
	cout << a * (b%10) << "\n"; // (3)
	cout << a * ((b/10) - ((b/100)*10)) << "\n"; // (4)
	cout << a * (b/100) << "\n"; // (5)
	cout << a * b; // (6);
	
	return 0;
}