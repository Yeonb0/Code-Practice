#include <iostream>
using namespace std;

int n, m;
int S[10];
void BT(int len, int start) { //BackTracking
	// break point
	if(len == m) {
		for(int i = 0; i < m; i++) cout << S[i] << " ";
		cout << "\n";
    return;
	}
	for(int i = start; i <= n; i++) {
		S[len] = i;
		BT(len + 1, i);
	}
}	

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	BT(0, 1);
	return 0;
}