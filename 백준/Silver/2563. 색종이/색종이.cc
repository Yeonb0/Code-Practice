#include <iostream>
using namespace std;

int A[101][101];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		for(int j = a; j < a + 10; j++) {
			for(int k = b; k < b + 10; k++) {
				A[j][k] = 1;
			}
		}
	}
	int ans = 0;
	for(int i = 0; i < 101; i++) {
		for(int j = 0; j < 101; j++) {
			if(A[i][j] == 1) ans++;
		}
	}
	cout << ans;
	return 0;
}