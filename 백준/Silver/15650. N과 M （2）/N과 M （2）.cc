#include <iostream>
using namespace std;
int S[10];
int n, m;

void BT(int len, int start) { // BackTracking
	if(len == m) { // b.p 
		for(int i = 0; i < m; i++) cout << S[i] << " ";
        cout << "\n";
	}
	
	for(int i = start; i <= n; ++i) {
		S[len] = i;
		BT(len + 1, i + 1);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	BT(0, 1);
	return 0;
}