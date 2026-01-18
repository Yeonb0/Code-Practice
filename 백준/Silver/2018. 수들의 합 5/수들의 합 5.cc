#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	long n;
	cin >> n;
	long start = 1, end = 1;
	int count = 1;
	int sum = 1;
	while(end != n) {
		if(sum < n) {
			sum += ++end;
		} else if (sum > n) {
			sum -= start++;
		} else {
			count++;
			sum += ++end;
		}
	}
	cout << count;
	return 0;
}