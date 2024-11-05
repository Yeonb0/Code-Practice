#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	int a, b;
	
	cin >> t;
	for(int i = 0; i < t; i++){
		cin >> a >> b;
		// 출력
		cout << "Case #" << i+1 << ": " << a << " + " << b << " = " << a+b << "\n";
	}	
	
	return 0;
}