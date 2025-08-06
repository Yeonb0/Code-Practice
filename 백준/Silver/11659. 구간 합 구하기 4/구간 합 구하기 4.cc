#include <iostream>
using namespace std;
int sum[100001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int m, n;
	cin >> m >> n;
	for(int i = 1; i <= m; i++) {
		int num;
        cin >> num;
		sum[i] = sum[i-1] + num;
	}
	while(n--) {
		int a, b;
		cin >> a >> b;
		cout << sum[b] - sum[a-1] << "\n";
	}
	return 0;
}