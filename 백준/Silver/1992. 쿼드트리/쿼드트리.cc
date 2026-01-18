#include <iostream>
#include <string>
using namespace std;
int video[65][65];
int n;

bool isSame(int x, int y, int size) {
	int val = video[x][y];
	for(int i = x; i < x+size; i++) {
		for(int j = y; j < y+size; j++) 
			if(video[i][j] != val) return false;
	}
	return true;
}

void divide(int x, int y, int size) {
	if(isSame(x, y, size)) {
		if(video[x][y] == 0) cout << "0";
		else cout << "1";
	} else {
		cout << "(";
		int resize = size / 2;
		for(int i = 0; i < 2; i++) {
			for(int j = 0; j < 2; j++) 
				divide(x + i*resize, y + j*resize, resize);
		}
		cout << ")";
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for(int j = 0; j < n; j++) video[i][j] = str[j]-'0';
	}
	
	divide(0, 0, n);
	return 0;
}