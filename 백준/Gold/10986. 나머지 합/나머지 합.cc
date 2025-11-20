#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	long tot = 0;
	cin >> n >> m;
	vector<long> S(n, 0);
	vector<long> C(m, 0);
	cin >> S[0];
	for(int i = 1; i < n; i++) {
		int temp;
		cin >> temp;
		S[i] = S[i-1] + temp;
	}
	for(int i = 0; i < n; i++) {
		int na = S[i] % m;
		if(na == 0) tot++;
		C[na]++;
	}
	for(int i = 0; i < m; i++) {
		if (C[i] > 1) {
			tot += (C[i] * (C[i]-1) / 2);
		}
	}
	cout << tot;
	return 0; 
}