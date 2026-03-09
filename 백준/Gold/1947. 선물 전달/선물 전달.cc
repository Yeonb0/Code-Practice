#include <iostream>
#define MOD 1000000000
using namespace std;

long D[1000001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	D[1] = 0;
	D[2] = 1;
	
	for(int i = 3; i <= n; i++) {
		D[i] = (i - 1) * (D[i - 2] + D[i - 1]) % MOD;
	}
	
	cout << D[n];
	
	return 0;
}