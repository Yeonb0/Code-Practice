#include <iostream>
using namespace std;

int paper[129][129];
int ans[2];
int n;

void DC(int a, int b, int n) {
	bool cut = false;
	int check = paper[a][b];
	for(int i = a; i < a + n; i++) {
		for(int j = b; j < b + n; j++) {
			if(check != paper[i][j]) {
				cut = true;
				break;
			}
		}
	}
	if(cut) {
		DC(a, b, n/2);
		DC(a + n/2, b, n/2);
		DC(a, b + n/2, n/2);
		DC(a + n/2, b + n/2, n/2);
	} else ans[check]++;
}
	
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			cin >> paper[i][j];
		}
	}
	
	DC(1, 1, n);
	cout << ans[0] << "\n" << ans[1];
	return 0;
}