#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	string num;
	int sum = 0;
	cin >> n;
	cin >> num;
	for (int i = 0; i < n; i++) {
		sum += num[i] - '0'; // 문자 -> 숫자로 변환
	}
	cout << sum;
	
	return 0;
}