#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	int sum = 1;
	int div = 1;
	for(int i = 0; i < k; i++) {
		sum *= (n-i);
		div *= (i+1);
	}
	int res = sum / div;
	cout << res;
	return 0;
}