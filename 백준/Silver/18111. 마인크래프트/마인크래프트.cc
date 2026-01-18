#include <iostream>
#include <algorithm>
using namespace std;

int land[501][501]; // 땅

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int minT = 99999999;
	int minH = 99999999;
	int time;
	int n, m, b;
	cin >> n >> m >> b;
	for(int i = 0; i < n; i++) 
		for(int j = 0; j < m; j++)
			cin >> land[i][j];
	
	for(int h = 0; h <= 256; h++) { // 각 높이마다 필요 시간 계산
		int d = 0; // 제거
		int s = 0; // 설치
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				if(land[i][j] > h) { // 제거해야 함
					d += land[i][j] - h;
				} else if(land[i][j] < h) { // 설치해야 함
					s += h - land[i][j];
				}
			}
		}
		if(d + b >= s) { // 블록이 충분하면
			time = d * 2 + s;
      if(time <= minT) {
    		minT = time;
    		minH = h;
      }
		}
	}
	cout << minT << "\n" << minH;
	return 0;
}