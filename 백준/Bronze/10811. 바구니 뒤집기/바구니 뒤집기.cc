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
		int a, b;
		cin >> a >> b;
		for(int i = 0; i < (b-a+1)/2; i++) {
			int tmp = box[a+i];
			box[a+i] = box[b-i];
			box[b-i] = tmp;
		}
	}
	for(int i = 1; i <= n; i++) cout << box[i] << " ";
	return 0;
}