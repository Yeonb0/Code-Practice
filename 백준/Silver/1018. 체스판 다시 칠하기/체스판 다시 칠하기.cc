#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string bor[50];
string WB[8] {
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW"
};
string BW[8] {
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB"
};

int WB_check(int x, int y) {
	int count = 0;
	for(int i = 0; i < 8; i++) {
		for(int j = 0; j < 8; j++) {
			if(bor[x+i][y+j] != WB[i][j]) count++;
		}
	}
	return count;
}

int BW_check(int x, int y) {
	int count = 0;
	for(int i = 0; i < 8; i++) {
		for(int j = 0; j < 8; j++) {
			if(bor[x+i][y+j] != BW[i][j]) count++;
		}
	}
	return count;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		cin >> bor[i];
	}
	int ans = 65;
	for(int i = 0; i <= n - 8; i++) {
		for(int j = 0; j <= m - 8; j++) {
			ans = min(WB_check(i, j), ans);
			ans = min(BW_check(i, j), ans);
		}
	}
	cout << ans;
	return 0;
}