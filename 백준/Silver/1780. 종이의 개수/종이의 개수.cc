#include <iostream>
using namespace std;
int paper[2200][2200];
int n;
int mi, ze, pl;
int size;

bool isSame(int x, int y, int size) {
	int val = paper[x][y];
	for(int i = x; i < x+size; i++) {
		for(int j = y; j < y+size; j++) 
			if(paper[i][j] != val) return false;
	}
	return true;
}

void divide(int x, int y, int size) {
	if(isSame(x, y, size)) {
		if(paper[x][y] == -1) mi++;
		else if(paper[x][y] == 0) ze++;
		else pl++;
	} else {
		int resize = size / 3;
		for(int i = 0; i < 3; i++) {
			for(int j = 0; j < 3; j++) {
				divide(x + i*resize, y + j*resize, resize);
			}
		}
	}
} 
		
		
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	// 입력
	cin >> n;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) cin >> paper[i][j];
	}
	// 재귀
	divide(0, 0, n);
	cout << mi << "\n" << ze << "\n" << pl;
	return 0;
}