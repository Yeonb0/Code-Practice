#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	int count = 0;
	cin >> n;
	vector<int> num(n);
	for (int i = 0; i < n; i++) cin >> num[i];
	for (int i = 0; i < n; i++) {
		bool prime = true;
		for (int j = 2; j < num[i]; j++) {
			if (num[i] % j == 0) prime = false;
		}
		if (num[i] != 1 && prime == true) count++;
	}
	cout << count;
	return 0;
}