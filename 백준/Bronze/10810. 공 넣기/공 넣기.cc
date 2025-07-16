#include <iostream>
using namespace std;
int box[101];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	while(m--) {
		int a, b, k;
		cin >> a >> b >> k;
		for(int i = a; i <= b; i++) box[i] = k;
	}
	for(int i = 1; i <= n; i++) cout << box[i] << " ";
	return 0;
}