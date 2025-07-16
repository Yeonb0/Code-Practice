#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int box[101];
	for(int i = 1; i <= 100; i++) box[i] = i;
	int n, m;
	cin >> n >> m;
	while(m--) {
		int a, b, tmp;
		cin >> a >> b;
		tmp = box[a];
		box[a] = box[b];
		box[b] = tmp;
	}
	for(int i = 1; i <= n; i++) cout << box[i] << " ";
	return 0;
}