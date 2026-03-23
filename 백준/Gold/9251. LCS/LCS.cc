#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string a, b;
int DP[1001][1001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> a >> b;
	
	for (int i = 1; i <= a.size(); i++) {
		for (int j = 1; j <= b.size(); j++) {
			if (a[i-1] == b[j-1]) DP[i][j] = DP[i-1][j-1] + 1;
			else {
				DP[i][j] = max(DP[i-1][j], DP[i][j-1]);
			}
		}
	}
	
	cout << DP[a.size()][b.size()];
	
	return 0;
}
