#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int num;
	cin >> num;
	// 1. 자릿수 구하기
	int k = 0;
	int num2 = num;
	while (num2) {
		num2 /= 10;
		k++;
	}
	// 2. n-(9*자릿수) ~ n 까지 분해합 구해보기
	for (int i = num-(9*k); i < num; i++) {
		int dsum = i;
		string snum = to_string(i);
		for (char c : snum) {
			dsum += c - '0';
		}
		// 3. 그중 제일 작은 거 출력
		if (dsum == num) {
			cout << i;
			return 0;
		}
	}
	cout << "0";
	return 0;
}